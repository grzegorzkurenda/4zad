#ifndef MONITOR_H
#define MONITOR_H

#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

#include "Event.h"
class Monitor :public QObject
{

Q_OBJECT
public:
    Monitor();
private slots:
    void notifyChange(const QString &path);
    void createEvent(QStringList newListDir,QStringList newListFile,const QString &path);
    QString findDeletedObjectName(QStringList newList,QStringList oldList);
private:
    QFileSystemWatcher *watcher;
    QFileSystemWatcher *watcher2;
    QString path;
    QStringList oldListFile,oldListDir;
};

#endif // MONITOR_H
