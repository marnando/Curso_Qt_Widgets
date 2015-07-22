#include "helloworld.h"
#include "ui_helloworld.h"
#include <QLabel>
#include <QHBoxLayout>

HelloWorld::HelloWorld(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelloWorld)
{
    //Configuração da UI
    ui->setupUi(this);

    //Criação de uma campo de texto
    QLabel * label = new QLabel(QString("Hello World!"));

    //Layout para organização dos elementos gráficos
    QHBoxLayout * hlay = new QHBoxLayout(this);

    //Adicionando uma widget dentro do layout
    hlay->addWidget(label);

    //Adicionando o layout na aplicação
    setLayout(hlay);

    //Informa que a altura máxima e mínima serão calculadas de acordo com as widgets
    //não redimensiona
//    setMaximumSize(hlay->sizeHint());
//    setFixedSize(sizeHint());
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    //Modifica o título da aplicação
    setWindowTitle(QString("Hello World"));
}

HelloWorld::~HelloWorld()
{
    delete ui;
}
