#ifndef LALE_LEARNINGSTRATEGIES_SIMPLETEACHER_H
#define LALE_LEARNINGSTRATEGIES_SIMPLETEACHER_H

#include "app/libs.h"
#include "teacher.h"
#include "core/scorerepository.h"
#include "core/roulettewheelselector.h"

namespace lale { namespace learningstrategies {

class SimpleTeacher : public Teacher
{
    Q_OBJECT

    QPointer<lale::core::ScoreRepository> scoreRepo;
    lale::core::RouletteWheelSelector<lale::core::Question> randomPicker;

public:
    explicit SimpleTeacher(QList<core::Question>, QPointer<lale::core::ScoreRepository>, QObject *parent = 0);
    virtual ~SimpleTeacher();

public slots:
    void provideNewQuestion();
    void wrongAnswerGiven(lale::core::Question);
    void rightAnswerGiven(lale::core::Question);
};

}}

#endif // LALE_LEARNINGSTRATEGIES_SIMPLETEACHER_H
