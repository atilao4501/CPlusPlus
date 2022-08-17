#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ordenavetores.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , ordenador(0)

{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_criar_clicked()
{
    try {
        ordenador = new afa::ordenavetores(ui->lineEdit_tamanho->text().toInt());
        //afa::ordenavetores vetorzao(ui->lineEdit_tamanho->text().toInt());

        ordenador->criarVetor();
        //vetorzao.criarVetor();
        ordenador->ordenarVetor();
        //vetorzao.ordenarVetor();

        ui->textEdit_vetor->setText(ordenador->getVetor());
        //ui->textEdit_vetor->setText(vetorzao.getVetor());
        ui->textEdit_vetorOrdenado->setText(ordenador->getVetorOrdenado());
        //ui->textEdit_vetorOrdenado->setText(vetorzao.getVetorOrdenado());

        delete ordenador;

    }  catch (QString &erro) {
            QMessageBox::information(this, "ERRO NO PROGRAMA", erro);
    }



}

