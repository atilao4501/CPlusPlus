#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <ordenador.h>
#include <QMessageBox>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Criar_clicked();

private:
    Ui::MainWindow *ui;
    afa::ordenador *ordenador;
};
#endif // MAINWINDOW_H
