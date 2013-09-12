#ifndef LALE_CORE_ROULETTEWHEELSELECTOR_H
#define LALE_CORE_ROULETTEWHEELSELECTOR_H

#include "app/libs.h"
#include "core/roulettearea.h"
#include "core/randomgenerator.h"

namespace lale { namespace core {

template<typename T>
class RouletteWheelSelector
{
public:
    typedef T VertexProperty;
    typedef RouletteArea<VertexProperty> Area;
    typedef boost::adjacency_list<boost::listS, boost::listS, boost::directedS, Area> Graph;
    typedef typename Graph::vertex_descriptor Vertex;

protected:
    Graph tree;
    Vertex root;
    RandomGenerator randomGenerator;

    template<typename input_iterator>
    Vertex createSubTrees(input_iterator start, input_iterator end)
    {
        int distance = std::distance(start, end);
        if(distance == 1) {
            return add_vertex(*start, tree);
        }

        input_iterator middle = start + distance / 2;
        Vertex first = createSubTrees(start, middle);
        Vertex second = createSubTrees(middle, end);

        double sum = tree[first].areaSize + tree[second].areaSize;
        Vertex parent = add_vertex(Area(boost::optional<VertexProperty>(), sum), tree);

        add_edge(parent, first, tree);
        add_edge(parent, second, tree);

        return parent;
    }

    VertexProperty pickRandomChildRecursivly(const Vertex & parent)
    {
        typename boost::graph_traits<Graph>::adjacency_iterator i, startChild, endChild;
        boost::tie(startChild, endChild) = boost::adjacent_vertices(parent, tree);

        if(std::distance(startChild, endChild) == 0) {
            return *(tree[parent].property);
        }

        double totalChildAreaSize = 0;
        for(i = startChild; i != endChild; ++i) {
            totalChildAreaSize += tree[*i].areaSize;
        }

        double areaSumLimit = randomGenerator.getRandomDouble(0, totalChildAreaSize);
        double currentAreaSum = 0;
        for(i = startChild; i != endChild; ++i) {
            currentAreaSum += tree[*i].areaSize;
            if(currentAreaSum >= areaSumLimit) {
                return pickRandomChildRecursivly(*i);
            }
        }

        throw std::logic_error("Random generator creates values that are too large");
    }

public:
    template<typename input_iterator>
    RouletteWheelSelector(input_iterator start, input_iterator end, RandomGenerator randomGenerator) :
        root(createSubTrees(start, end)),
        randomGenerator(randomGenerator)
    {
    }

    VertexProperty pickRandom()
    {
        return pickRandomChildRecursivly(root);
    }

    virtual ~RouletteWheelSelector()
    {
    }
};

}}

#endif // LALE_CORE_ROULETTEWHEELSELECTOR_H
