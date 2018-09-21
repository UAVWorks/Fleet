// Qt
#include <QCoreApplication>

// Tests
#include "links_test.h"

#define execTest(T) { T t; QTest::qExec(&t); }

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);

    execTest(LinksTest)

    return 0;
}
