#include "Monitor.h"

Monitor::Monitor()
{
     //QTextStream qtin(stdin);
     path=("C:/Users/root/Desktop/studia/semestr 5/KDM/zaj2");
     //qtin.readLine();  // This is how you read the entire line

     watcher->addPath(path);
     QDir dir(path);
     dir.setFilter(QDir::Dirs|QDir::Files);
     connect(watcher,SIGNAL(directoryChanged(QString)),this,SLOT(notifyChange(QString)));
     connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(notifyChange(QString)));


}
void Monitor::notifyChange(const QString &path)
{
    qDebug() << "Signal Received";

    QStringList oldList,newList;


}
