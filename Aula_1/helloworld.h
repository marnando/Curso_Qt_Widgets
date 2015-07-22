#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <QWidget>

namespace Ui {
class HelloWorld;
}

class HelloWorld : public QWidget
{
    Q_OBJECT

public:
    explicit HelloWorld(QWidget *parent = 0);
    ~HelloWorld();

private:
    Ui::HelloWorld *ui;
};

#endif // HELLOWORLD_H
