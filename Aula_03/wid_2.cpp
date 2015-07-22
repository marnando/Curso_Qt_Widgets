#include "wid_2.h"
#include <QHBoxLayout>

wid_2::wid_2(QWidget *parent) :
    QWidget(parent)
{
    //Modificando o título da janela
    setWindowTitle("wid_2");

    cont = 1;

    //Instanciando os elementos
    QHBoxLayout * hLay = new QHBoxLayout(this);
    myLineEdit = new QLineEdit(this);

    //Adiciono um texto padrão
    myLineEdit->setText("Mude meu texto");

    //Digo que meu elemento estará desabilitado para edição
    myLineEdit->setEnabled(false);

    //Adicionando QLineedit no layout
    hLay->addWidget(myLineEdit);

    //Adicionando o lauout a ao layout da aplicação
    setLayout(hLay);
}

wid_2::~wid_2()
{
}

/*
 * Essa função SLOT tem como objetivo modificar o texto do QLineEdit
 * incrementando com o contador
 */
void wid_2::onChanceLineText()
{
    if (cont > 1) {
        myLineEdit->setText(tr("Mudou %1 vezes!").arg(cont));
    } else {
        myLineEdit->setText(tr("Mudou %1 vez!").arg(cont));
    }

    cont++;
}
