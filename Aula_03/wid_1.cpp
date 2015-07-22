#include "wid_1.h"
#include <QHBoxLayout>
#include <QPushButton>

wid_1::wid_1(QWidget *parent) :
    QWidget(parent)
{

    //Modificando o título da janela
    setWindowTitle("wid_1");

    //Instanciando os objetos, QHBoxLayout e QPushButton
    QHBoxLayout * hLay = new QHBoxLayout(this);
    QPushButton * myBtn = new QPushButton("Aperte-me!", this);

    //Adicionando o QPushButton no layout
    hLay->addWidget(myBtn);

    //Setando o layout principal da aplicação
    setLayout(hLay);

    //Conectando eventos do clique do botão com a função onClickedPushButton()
    connect(myBtn, SIGNAL(clicked()), this, SLOT(onClickedPushButton()));
}

wid_1::~wid_1()
{
}

void wid_1::onClickedPushButton()
{
    //Enviando um signal para que a outra Widget possa capturar e mudar o texto do QLineEdit
    emit signalClickedChangeText();
}
