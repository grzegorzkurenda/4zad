#include "Monitor.h"
#include "Event.h"
Monitor::Monitor()
{
     QTextStream qtin(stdin);
     //path=("C:/Users/root/Desktop");
     path=qtin.readLine();

     watcher = new QFileSystemWatcher;
     watcher->addPath(path);

     QDir dir(path);
     dir.setFilter(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
     dir.setSorting(QDir::Time);

    QFileInfoList list = dir.entryInfoList();
     for(int i=0;i<list.size();i++)
     {
         if(list.at(i).isDir())
         {
             oldListDir<<list.at(i).absoluteFilePath();
         }
         else{
            oldListFile<<list.at(i).absoluteFilePath();
         }
     }
     watcher2 = new QFileSystemWatcher;
     watcher2->addPaths(oldListFile);

     connect(watcher,SIGNAL(directoryChanged(QString)),this,SLOT(notifyChange(QString)));
     connect(watcher2,SIGNAL(fileChanged(QString)),this,SLOT(notifyChange(QString)));

}
void Monitor::notifyChange(const QString &path)
{
    qDebug() << "\nSignal Received";

    QStringList newListDir,newListFile;

    QDir dir(this->path);
    dir.setFilter(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);
    dir.setSorting(QDir::Time);
    QFileInfoList list = dir.entryInfoList();
     for(int i=0;i<list.size();i++)
     {
         if(list.at(i).isDir())
         {
             newListDir<<list.at(i).absoluteFilePath();
         }
         else{
             newListFile<<list.at(i).absoluteFilePath();
         }
     }

    createEvent(newListDir,newListFile,path);

    watcher2->removePaths(oldListFile);
    oldListDir=newListDir;
    oldListFile=newListFile;
    watcher2->addPaths(oldListFile);
}



void Monitor::createEvent(QStringList newListDir,QStringList newListFile,const QString &path){
    if(newListDir.size()>oldListDir.size())
    {
        Event("Created","Dir",newListDir.at(0));
    }
    else if(newListDir.size()<oldListDir.size())
    {
        Event("Deleted","Dir",findDeletedObjectName(newListDir,oldListDir));
    }
    else if(newListFile.size()>oldListFile.size())
    {
        Event("Created","File",newListFile.at(0));
    }
    else if(newListFile.size()<oldListFile.size())
    {
        Event("Deleted","File",findDeletedObjectName(newListFile,oldListFile));
    }
    else if((newListDir==oldListDir)&&(newListFile==oldListFile))
    {
        Event("Edited","File",path);
    }
    else if(newListDir!=oldListDir){

        Event("Rename","Dir",newListDir.at(0));
    }
    else {
        Event("Rename","File",newListFile.at(0));
    }

}

QString Monitor::findDeletedObjectName(QStringList newList,QStringList oldList){

    if(newList.isEmpty()){return oldList.at(0);}

    for(int i=0;i<newList.size();i++)
    {
        if(newList.at(i)!=oldList.at(i))
        {
            return oldList.at(i);
        }
    }
    return oldList.at(newList.size());
}



