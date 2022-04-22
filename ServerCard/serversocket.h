#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QTcpSocket>

class ServerSocket : public QTcpSocket
{
    Q_OBJECT
public:
    ServerSocket(qintptr handle, QObject *parent = nullptr);

signals:
    void SocketReadyRead(ServerSocket *);
    void SocketStateChanged(ServerSocket *, int );
};


#endif // SERVERSOCKET_H
