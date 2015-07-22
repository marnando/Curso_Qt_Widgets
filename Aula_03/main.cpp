#include "wid_1.h"
#include "wid_2.h"
#include <QApplication>
#include <QObject>
#include <QSplitter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Criando os objetvos gráficos
    wid_1 wid1;
    wid_2 wid2;

    //Connectando a função SIGNAL da wid_1 com a função SLOT da wid_2
    QObject::connect(&wid1, SIGNAL(signalClickedChangeText())
                   , &wid2, SLOT(onChanceLineText()));

    //Criando um objeto QSplitter que tem a função de dividir a aplicação em partes
    QSplitter splitter;

    //Adicionando as UIs dentro do QSplitter
    splitter.addWidget(&wid1);
    splitter.addWidget(&wid2);

    //Mando exibir
    splitter.show();

    return a.exec();
}
