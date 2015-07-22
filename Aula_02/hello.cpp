#include "hello.h"
#include "ui_hello.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Hello::Hello(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Hello)
{
    ui->setupUi(this);

    //Criando elementos gráficos: 2 Labels e 2 botões
    QLabel * instituicao = new QLabel("Instituição: Funceme");
    QLabel * funcionario = new QLabel("Funcionário: Marnando Júnior");
    QPushButton * buttonOk = new QPushButton(this);
    QPushButton * buttonAbout = new QPushButton(this);

    //Mudar o texto dos botões
    buttonOk->setText(QString("Ok"));
    buttonAbout->setText(QString("About"));

    //Instancio os 2 layouts: 1 vertical e 1 horizontal
    QVBoxLayout * vLay = new QVBoxLayout(this);
    QHBoxLayout * hLay = new QHBoxLayout(this);

    vLay->addWidget(instituicao);
    vLay->addWidget(funcionario);
    hLay->addWidget(buttonOk);
    hLay->addWidget(buttonAbout);

    vLay->addLayout(hLay);

    setLayout(vLay);

    setFixedSize(sizeHint());
}

Hello::~Hello()
{
    delete ui;
}
