// Qt
#include <QApplication>
#include <QLockFile>
#include <QFontDatabase>
#include <QIcon>
#include <QQmlContext>
#include <QDebug>

// Internal
#include "qml_main_presenter.h"

int main(int argc, char* argv[])
{
    QLockFile lock("FLEET");
    if (!lock.tryLock())
    {
        qFatal("Application Fleet is locked");
    }

#ifdef Q_OS_WIN32
    QApplication::setAttribute(Qt::AA_UseOpenGLES);
#endif

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    app.setApplicationName("Fleet");
    app.setOrganizationName("Digital.Aero");

    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Italic.ttf");
    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Regular.ttf");

    app.setFont(QFont("OpenSans"));
    app.setWindowIcon(QIcon(":/icons/fleet.svg"));

    presentation::QmlMainPresenter presenter;
    presenter.start();

    return app.exec();
}
