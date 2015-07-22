#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    setWindowTitle(tr("Cadastro"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::testaRestricoes()
{
    QString textError = QString();
    bool    question  = false;
    int     ret       = 0;

    switch (ui->tabWidget->currentIndex()) {
    case 0: // primeira aba
    {
        //Antes de avançar preciso saber se todos os campos estão preenchidos
        if (ui->m_lineEditNome->text().isEmpty())
        {
            textError = tr("Você precisa informar o seu 'Nome' para avançar para a próxima página.");
        } else
        if (ui->m_lineEditEmail->text().isEmpty())
        {
            textError = tr("Você precisa informar o seu 'Email' para avançar para a próxima página.");
        } else
        if (ui->m_textEditSobreMim->toPlainText().isEmpty())
        {
            question = true;
            textError = tr("Não quer nos falar mais sobre você? Então preencha todo o formulário, \ncaso não, clique em 'NÃO'.");
        }
    }
        break;
    case 1: // segunda aba
    {
        //Antes de salvar preciso saber se todos os campos estão preenchidos
        if (ui->m_lineEditEmpresa->text().isEmpty())
        {
            textError = tr("Você precisa informar o seu 'Empresa' para avançar para a próxima página.");
        } else
        if (ui->m_lineEditCargo->text().isEmpty())
        {
            textError = tr("Você precisa informar o seu 'Cargo' para avançar para a próxima página.");
        } else
        if (ui->m_textEditObjetivos->toPlainText().isEmpty())
        {
            question = true;
            textError = tr("Não quer nos falar mais sobre seus objetivos? Então preencha todo o formulário, caso não, clique em 'Sim'.");
        }
    }
        break;
    default:
        break;
    }

    if (!textError.isEmpty()) {
        if (question)
        {
            ret = QMessageBox::question(this, tr("Atenção"), textError, QMessageBox::Yes, QMessageBox::No);
        } else
        {
            ret = QMessageBox::warning(this, tr("Atenção"), textError, QMessageBox::Ok);
        }
    }

    return ret;
}

bool MainWindow::testaRestricoesOtimizado(int index)
{
    bool    ret  = true;

    if (index == 1)
    {
        //Antes de avançar preciso saber se todos os campos estão preenchidos
        if (ui->m_lineEditNome->text().isEmpty()
        ||  ui->m_lineEditEmail->text().isEmpty())
        {
            ret = false;
        }
    }

    return ret;
}

void MainWindow::on_actionExit_triggered()
{
    int retorno = 0;

    retorno =
    QMessageBox::question(this
                        , tr("Atenção")
                        , tr("Deseja sair?")
                        , QMessageBox::Yes | QMessageBox::No);

    if (retorno == QMessageBox::Yes)
    {
        close();
    } else
    {
        //...
    }

    /*

    // Tipos de alerta
    QMessageBox::information(this
                           , tr("Atenção")
                           , tr("Esse é somente informativo.")
                           , QMessageBox::Ok);



    retorno =
    QMessageBox::warning(this
                       , tr("Atenção")
                       , tr("Esse informativo pode ser crítico!!")
                       , QMessageBox::Yes
                       , QMessageBox::No
                       , QMessageBox::Cancel);



    // Outra forma de exibir uma mensagem
    QMessageBox msgBox;
    msgBox.setText(tr("Atenção"));
    msgBox.setInformativeText(tr("Deseja sair do sistema?"));
    msgBox.setStandardButtons(QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    */


}

void MainWindow::on_actionAbout_triggered()
{
//    QApplication::aboutQt();
    qApp->aboutQt();
}

void MainWindow::on_m_btnLimpar_clicked()
{
    //Limpar todos os meus campos de texto
    ui->m_lineEditNome->clear();
    ui->m_lineEditEmail->clear();
    ui->m_lineEditCargo->clear();
    ui->m_lineEditEmpresa->clear();
    ui->m_textEditSobreMim->clear();
    ui->m_textEditObjetivos->clear();
}

void MainWindow::on_m_btnAvancar_clicked()
{
    switch (testaRestricoes()) {

    case QMessageBox::No:

        //Avanço para a próxima página
        ui->tabWidget->setCurrentIndex(1);

        break;

    case QMessageBox::Yes:

        //Permaneço para editar o campo

        break;

    case QMessageBox::Ok:

        //Permaneço, não avanço, ocorreu um erro!

        break;

    default:
        ui->tabWidget->setCurrentIndex(1);
        break;
    }
}

void MainWindow::on_m_btnCancelar_clicked()
{
    int ret = QMessageBox::question(this
                                  , tr("Atenção")
                                  , tr("Deseja cancelar o cadastro?")
                                  , QMessageBox::Yes
                                  , QMessageBox::No);

    switch (ret) {

    case QMessageBox::Yes:
    {
        //Limpo os dados
        on_m_btnLimpar_clicked();

        //Volto para primeira aba
        ui->tabWidget->setCurrentIndex(0);
    }
        break;

    default:
        break;
    }
}

void MainWindow::on_m_btnSalvar_clicked()
{
    switch (testaRestricoes()) {

    case QMessageBox::No:

        //Avanço para salvar o resumo

        break;

    case QMessageBox::Yes:

        //Permaneço para edição

        break;

    case QMessageBox::Ok:

        //Permaneço, não salvo, ocorreu um erro!

        break;

    default:
        ui->tabWidget->setCurrentIndex(1);
        break;
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    //Esse define indica que a variável não está sendo utilizada, não causa warnings na compilação
    Q_UNUSED(index)

    if (!testaRestricoesOtimizado(index))
    {
        ui->tabWidget->setCurrentIndex(0);
        QMessageBox::information(this
                               , tr("Atenção")
                               , tr("Preencha os dados na primeira página para avançar.")
                               , QMessageBox::Ok);

    }
}
