#ifndef WID_1_H
#define WID_1_H

#include <QWidget>

namespace Ui {
class wid_1;
}

class wid_1 : public QWidget
{
    Q_OBJECT

public:
    explicit wid_1(QWidget *parent = 0);
    ~wid_1();

signals:
    void signalClickedChangeText();

public slots:
    void onClickedPushButton();
};

#endif // WID_1_H
