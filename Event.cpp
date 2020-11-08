#include "Event.h"

Event::Event(QObject *parent) : QObject(parent)
{

}
Event::Event(QString type,QString dir_file,QString path){
    this->type=type;
    this->dir_file=dir_file;
    this->path=path;
    message();
    createLogs(this->toString());
}

void Event::message(){
    qDebug()<<this->type<<","<<this->dir_file<<","<<this->path;
}

QString Event::toString(){
    return this->type+","+this->dir_file+","+this->path;
}

void Event::createLogs(QString eventName){

    QFile file("logs.txt");

     if (!file.open(QIODevice::WriteOnly |QIODevice::Append | QIODevice::Text))
    {
        qDebug()<<"nie ma pliku logs.txt";
           return;
    }
       QTextStream out(&file);
       QDateTime now = QDateTime::currentDateTime();
       out <<now.date().toString() << " " << now.time().toString() << " " << eventName << "\n";
       file.close();

}
