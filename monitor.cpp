#include "Monitor.h"

Monitor::Monitor()
{
     //QTextStream qtin(stdin);
     path=("C:/Users/root/Desktop/studia/semestr 5/KDM/zaj2");
     //qtin.readLine();  // This is how you read the entire line

    watcher = new QFileSystemWatcher;
     watcher->addPath(path);

     QDir dir(path);

     dir.setFilter(QDir::Dirs|QDir::Files);
     dir.setSorting(QDir::Size|QDir::Reversed);
     connect(watcher,SIGNAL(directoryChanged(QString)),this,SLOT(NotifyChange(QString)));
     connect(watcher,SIGNAL(fileChanged(QString)),this,SLOT(NotifyChange(QString)));


}
void Monitor::NotifyChange(const QString &path)
{
    qDebug() << "Signal Received";

    QStringList oldList,newList;


}
