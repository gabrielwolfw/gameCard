#include "serversocket.h"


ServerSocket::ServerSocket(qintptr handle, QObject *parent)
    : QTcpSocket(parent)
{
    setSocketDescriptor(handle);
    connect(this, &ServerSocket::readyRead, [&](){
        emit SocketReadyRead(this);
    });

    connect(this, &ServerSocket::stateChanged, [&](int S){
        emit SocketStateChanged(this,S);
    });


}
