#ifndef QML_MAIN_PRESENTER_H
#define QML_MAIN_PRESENTER_H

// Internal
#include "i_main_presenter.h"

namespace presentation
{
    class QmlMainPresenter: public IMainPresenter
    {
        Q_OBJECT

    public:
        explicit QmlMainPresenter(QObject* parent = nullptr);
        virtual ~QmlMainPresenter();

    public slots:
        void start() override;

    private:
        class Impl;
        QScopedPointer<Impl> const d;
    };
}

#endif // QML_MAIN_PRESENTER_H
