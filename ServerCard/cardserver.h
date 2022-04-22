#ifndef CARDSERVER_H
#define CARDSERVER_H
#include <QTcpServer>
#include <QList>


class ServerSocket;

class cardServer : public QTcpServer
{
public:
    cardServer(QObject *parent = nullptr);

    bool startServer(quint16 port = 0);

protected:
    void incomingConnection(qintptr handle);

private:
    QList<ServerSocket *> cardSockets;
};

#endif // CARDSERVER_H
