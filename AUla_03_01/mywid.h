#ifndef MYWID_H
#define MYWID_H

#include <QWidget>
#include <QSlider>
#include <QLabel>

class MyWid : public QWidget
{
    Q_OBJECT

public:
    QSlider * m_slider;
    QLabel * m_label;

    MyWid(QWidget *parent = 0);
    ~MyWid();

public slots:
    void onChangeValues(int a);
};

#endif // MYWID_H
