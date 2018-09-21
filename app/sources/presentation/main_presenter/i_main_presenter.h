#ifndef I_MAIN_PRESENTER_H
#define I_MAIN_PRESENTER_H

// Qt
#include <QObject>

namespace presentation
{
    class IMainPresenter: public QObject
    {
        Q_OBJECT

    public:
        explicit IMainPresenter(QObject* parent) : QObject(parent) {}

    public slots:
        virtual void start() = 0;
    };
}

#endif // I_MAIN_PRESENTER_H
