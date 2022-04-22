#include "cardserver.h"
#include "serversocket.h"
#include <QDebug>
#include <QTextStream>
//14,18 terminar en la madrugada

cardServer::cardServer(QObject *parent)
    :QTcpServer(parent)
{

}

bool cardServer::startServer(quint16 port){
    return listen(QHostAddress::Any, port);
}

void cardServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle" << handle;

    auto socket = new ServerSocket(handle, this);
    cardSockets << socket;

    for(auto i : cardSockets ){
        QTextStream T(i);
        T << "Server: Client has been connected" << handle;
        i->flush();
    }

    connect(socket, &ServerSocket::SocketReadyRead,[&](ServerSocket *S){
        qDebug() << "Executing SocketReadyRead";
        QTextStream T(S);
        auto text = T.readAll();

        for (auto i : cardSockets){
            QTextStream Q(i);
            Q << text;
            i->flush();
        }
    });
    connect(socket, &ServerSocket::SocketStateChanged, [&](ServerSocket *S, int ST){
        if (ST == QTcpSocket::UnconnectedState){
            qDebug() << "status: Unconnected handle"<<S->socketDescriptor();

            cardSockets.removeOne(S);
            for (auto i:cardSockets){
                QTextStream K(i);
                K << "Client " << S->socketDescriptor() << "has been desconnected...";
                i ->flush();
            }

        }
    });
}
