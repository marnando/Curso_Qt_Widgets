#include "mywid.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWid w;
    w.show();

    return a.exec();
}
