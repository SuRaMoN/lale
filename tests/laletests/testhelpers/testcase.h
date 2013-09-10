#ifndef LALETESTS_TESTHELPERS_TESTCASE_H
#define LALETESTS_TESTHELPERS_TESTCASE_H

#include "app/lale.h"

namespace laletests { namespace testhelpers {

class TestCase : public QObject
{
    Q_OBJECT
protected:
    void createNewDatabase(const QString &);

public:
    explicit TestCase(QObject *parent = 0);
    virtual ~TestCase();
};

}}

#endif // LALETESTS_TESTHELPERS_TESTCASE_H
