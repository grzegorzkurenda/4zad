#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDebug>
#include <QDateTime>
#include <QFile>
class Event : public QObject
{
    Q_OBJECT

public:

    explicit Event(QObject *parent = nullptr);
    Event(QString type,QString dir_file,QString path);
    void createLogs(QString eventName);

private:

    void message();
    QString toString();

    QString type;
    QString dir_file;
    QString path;
};

#endif // EVENT_H
