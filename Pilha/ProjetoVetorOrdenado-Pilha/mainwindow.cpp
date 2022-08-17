#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (ordenador) delete ordenador;
    delete ui;

}


void MainWindow::on_pushButton_Criar_clicked()
{
    try {

            ordenador = new afa::ordenador(ui->lineEdit_tamanho->text().toInt());

            ordenador->ordenarVetor();

            ui->textEdit_vetor->setText(ordenador->getVetor());
            ui->textEdit_vetorOrdenado->setText(ordenador->getVetorOrdenado());

            delete ordenador;



    }  catch (QString &erro) {
        QMessageBox::information(this, "ERRO NO PROGRAMA", erro);

    }
    catch (std::bad_alloc&) {
       throw QString("Memoria insuficiente");
   }

}

