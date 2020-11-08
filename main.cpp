#include <QCoreApplication>
#include "Monitor.h"
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Monitor monitor;

    return a.exec();
}



