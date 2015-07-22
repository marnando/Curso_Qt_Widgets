#include "mywid.h"
#include <QGridLayout>

/**
 * Essa classe servirá como exemplo entre signals e slots
 * @brief MyWid::MyWid
 * @param parent
 */
MyWid::MyWid(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Aula 03");

    //Instanciando os elementos gráficos e setando os parents
    QGridLayout * grid = new QGridLayout(this);
    m_slider = new QSlider(Qt::Horizontal, this);
    m_label = new QLabel(this);

    //Setando o range min e max do slider
    m_slider->setRange(0, 100);

    //Passando o valor incial '0' para ser exibido no label
    m_label->setText(QString::number(0));

    //Adicionando as widgets dentro do grid
    //widget | row | col
    grid->addWidget(m_slider, 0, 0);
    grid->addWidget(m_label, 0, 1);

    //Adicionando o layout da aplicação
    setLayout(grid);

    //Conectando os eventos
    connect(m_slider, SIGNAL(valueChanged(int))
          , this, SLOT(onChangeValues(int)));
}

MyWid::~MyWid()
{

}

void MyWid::onChangeValues(int a)
{
   QString style;
   if (a >= 10 && a <= 29) {
       style = QString("background-color: red");
   } else
   if (a >= 30 && a <= 49) {
       style = QString("background-color: lightblue");
   } else
   if (a >= 50 && a <= 79) {
       style = QString("background-color: orange");
   } else
   if (a >= 80 && a <= 100) {
       style = QString("background-color: purple");
   }

   //Incrementando o contador
   m_label->setText(QString("%1").arg(a));

   //Modificando o estilo de exibição usando o CSS
   m_label->setStyleSheet(style);


}
