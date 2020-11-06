#ifndef MONITOR_H
#define MONITOR_H

#include <QFileSystemWatcher>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

class Monitor :public QObject
{

Q_OBJECT
public:
    Monitor();
private slots:
    void NotifyChange(const QString &path);
private:
    QFileSystemWatcher *watcher;
    QString path;
};

#endif // MONITOR_H
