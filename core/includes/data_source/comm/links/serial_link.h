#ifndef SERIAL_LINK_H
#define SERIAL_LINK_H

#include "abstract_link.h"

class QSerialPort;

namespace data_source
{
    class SerialLink: public AbstractLink
    {
        Q_OBJECT

    public:
        SerialLink(const QString& device = QString(), qint32 baudRate = 0, QObject* parent = nullptr);

        bool isConnected() const override;
        bool waitData(int timeout = 5000) override;

        QString device() const;
        qint32 baudRate() const;

    public slots:
        void connectLink() override;
        void disconnectLink() override;

        void setDevice(const QString& device);
        void setBaudRate(qint32 baudRate);

    signals:
        void deviceChanged(QString device);
        void baudRateChanged(qint32 baudRate);

    protected:
        bool sendDataImpl(const QByteArray& data) override;

    private slots:
        void readSerialData();
        void onError(int error);

    private:
        QSerialPort* m_port;
    };
}

#endif // SERIAL_LINK_H
