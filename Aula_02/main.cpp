#include "hello.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hello w;
    w.showNormal();

    return a.exec();
}
