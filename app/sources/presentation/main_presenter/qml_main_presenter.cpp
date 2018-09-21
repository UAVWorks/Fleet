#include "qml_main_presenter.h"

// Qt
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

#include "gui_style_manager.h"

using namespace presentation;

class QmlMainPresenter::Impl
{
public:
    QQmlApplicationEngine* const engine;

    GuiStyleManager manager;

    Impl(QmlMainPresenter* p):
        engine(new QQmlApplicationEngine(p)),
        manager(engine->rootContext())
    {}
};

QmlMainPresenter::QmlMainPresenter(QObject* parent):
    IMainPresenter(parent),
    d(new Impl(this))
{
    d->engine->addImportPath(QStringLiteral("qrc:/"));

    d->manager.setPaletteStyle(GuiStyleManager::Night); // TODO: settings
    d->manager.setSizings(36);

    connect(d->engine, &QQmlEngine::quit, qApp, &QGuiApplication::quit);
}

QmlMainPresenter::~QmlMainPresenter()
{}

void QmlMainPresenter::start()
{
    d->engine->load(QStringLiteral("qrc:/MainView.qml"));
}
