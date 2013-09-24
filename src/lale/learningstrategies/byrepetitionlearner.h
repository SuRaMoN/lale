#ifndef LALE_LEARNINGSTRATEGIES_BYREPETITIONLEARNER_H
#define LALE_LEARNINGSTRATEGIES_BYREPETITIONLEARNER_H

#include "app/libs.h"
#include "learner.h"
#include "core/scorerepository.h"
#include "core/roulettewheelselector.h"

namespace lale { namespace learningstrategies {

class ByRepetitionLearner : public Learner
{
    Q_OBJECT

protected:
    unsigned int repeatPoolMaxScoreSum;
    unsigned int numRightAnswersToRemoveFromRepeatPool;

    QPointer<lale::core::ScoreRepository> scoreRepo;
    lale::core::RandomGenerator randomGenerator;
    lale::core::RouletteWheelSelector<lale::core::Question> randomQuestionPicker;
    lale::core::RouletteWheelSelector<lale::core::Question> repeatPoolRandomQuestionPicker;

public:
    explicit ByRepetitionLearner(QList<core::Question>, QPointer<lale::core::ScoreRepository>, lale::core::RandomGenerator, QObject *parent = 0);
    virtual ~ByRepetitionLearner();

    unsigned int getRepeatPoolMaxScoreSum() const;
    void setRepeatPoolMaxScoreSum(unsigned int value);

    unsigned int getNumRightAnswersToRemoveFromRepeatPool() const;
    void setNumRightAnswersToRemoveFromRepeatPool(unsigned int value);

public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_BYREPETITIONLEARNER_H
