#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    /**
     * Verifica as restrições do sistema
     * @brief testaRestricoes
     * @return
     */
    int testaRestricoes();

    /**
     * Faz um rápido teste para verificar se está tudo ok
     * @brief testaRestricoesOtimizado
     * @return
     */
    bool testaRestricoesOtimizado(int index);

private slots:
    /**
     * Ação de finalizar o programa
     * @brief on_actionExit_triggered
     */
    void on_actionExit_triggered();

    /**
     * Ação de mostrar um alerta sobre QtCreator
     * @brief on_actionAbout_triggered
     */
    void on_actionAbout_triggered();

    /**
     * Limpa os campos de livre edição
     * @brief on_m_btnLimpar_clicked
     */
    void on_m_btnLimpar_clicked();

    /**
     * Responsável por mudar a tab
     * @brief on_m_btnAvancar_clicked
     */
    void on_m_btnAvancar_clicked();

    /**
     * Cancela todo o procedimento, limpa os dados e volta para a janela principal
     * @brief on_m_btnCancelar_clicked
     */
    void on_m_btnCancelar_clicked();

    /**
     * Responsável pelo salvamento do registro
     * @brief on_m_btnSalvar_clicked
     */
    void on_m_btnSalvar_clicked();

    /**
     * Verifica uma ação no momento da troca de tabs
     * @brief on_tabWidget_currentChanged
     * @param index
     */
    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
