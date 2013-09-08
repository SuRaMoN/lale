#ifndef LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H
#define LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H

#include <QObject>

namespace laletests { namespace learningstrategies {

class NaiveLearnerTest : public QObject
{
    Q_OBJECT

public:
    explicit NaiveLearnerTest(QObject *parent = 0);
    virtual ~NaiveLearnerTest();

private slots:
    void testGivesRandomQuestions();
};

}}

#endif // LALETESTS_LEARNINGSTRATEGIES_NAIVELEARNERTEST_H
