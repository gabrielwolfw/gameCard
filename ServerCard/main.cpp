#include <QCoreApplication>
#include "cardserver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cardServer Server;
    if (!Server.cardServer::startServer(3333)){
        qDebug() << "Error"<<Server.errorString();
        return 1;
    }else
    {
        qDebug() << "Server has started";
    }

    return a.exec();
}
