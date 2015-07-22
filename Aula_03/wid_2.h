#ifndef WID_2_H
#define WID_2_H

#include <QWidget>
#include <QLineEdit>

//namespace Ui {
//class wid_2;
//}

class wid_2 : public QWidget
{
    Q_OBJECT

public:
    int cont;
    QLineEdit * myLineEdit;

    explicit wid_2(QWidget *parent = 0);
    ~wid_2();

public slots:
    void onChanceLineText();

private:
//    Ui::wid_2 *ui;
};

#endif // WID_2_H
