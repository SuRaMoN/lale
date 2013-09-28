#ifndef LALE_LEARNINGSTRATEGIES_BYREPETITIONTEACHER_H
#define LALE_LEARNINGSTRATEGIES_BYREPETITIONTEACHER_H

#include "app/libs.h"
#include "teacher.h"
#include "core/scorerepository.h"
#include "core/roulettewheelselector.h"

namespace lale { namespace learningstrategies {

class ByRepetitionTeacher : public Teacher
{
    Q_OBJECT

protected:
    unsigned int repeatPoolMaxScoreSum;
    unsigned int numRightAnswersToRemoveFromRepeatPool;

    lale::core::Question previousQuestion;
    QPointer<lale::core::ScoreRepository> scoreRepo;
    lale::core::RandomGenerator randomGenerator;
    lale::core::RouletteWheelSelector<lale::core::Question> randomQuestionPicker;
    lale::core::RouletteWheelSelector<lale::core::Question> repeatPoolRandomQuestionPicker;

    lale::core::Question getNewQuestionCandidate();

public:
    explicit ByRepetitionTeacher(QList<core::Question>, QPointer<lale::core::ScoreRepository>, lale::core::RandomGenerator, QObject *parent = 0);
    virtual ~ByRepetitionTeacher();

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

#endif // LALE_LEARNINGSTRATEGIES_BYREPETITIONTEACHER_H
