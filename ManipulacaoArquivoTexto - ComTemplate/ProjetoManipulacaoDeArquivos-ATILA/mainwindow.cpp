#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ordena.h>
#include <QMessageBox>
#include <QString>


using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;
using std::istringstream;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAbrirArquivo_clicked()
{

    try {
        // criando um arquivo de entrada
        //ifstream é o tipo
        std::ifstream arquivo;

        //Buscando o arquivo no disco
        QString nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

        // abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivo.toStdString().c_str());

        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser aberto");
        }

        std::string linha;
        QString texto;

        // lendo do arquivo
        getline(arquivo,linha);

        // Teste de fim do arquivo
        while(!arquivo.eof()){

            texto += QString::fromStdString(linha);
            texto += "\n";
            //lendo do arquivo
            getline(arquivo,linha);
        }
        // fechado o arquivo de entrada
        arquivo.close();
        ui->textEditSaida->setText(texto);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }



}


void MainWindow::on_pushButtonCriarNovoArquivo_clicked()
{
    try {
        QString texto = ui->textEditSaida->toPlainText();
        if(texto.isEmpty()) throw QString("Digitar o texto antes de Salvar");
        // criando um arquivo de entrada
        std::ofstream arquivo;

        //Buscando o arquivo no disco
        QString nomeDoArquivo = QFileDialog::getSaveFileName(this,"Criar Novo Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

        // abrindo um arquivo de entrada
        arquivo.open(nomeDoArquivo.toStdString().c_str());

        // verificando erro de abertura do arquivo de entrada
        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser Criado");
        }

        arquivo<<texto.toStdString().c_str()<<std::endl;
        arquivo.close();
        ui->textEditSaida->clear();

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonLimparCaixa_clicked()
{
    ui->textEditSaida->clear();
}

void MainWindow::on_pushButtonIncluirNoFinal_clicked()
{
    try {


    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_Ordenar_clicked()
{   
    try {

        afa::ordena objeto;

        QString NomesGrid, NumerosGrid;

        QString nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");


        if (ui->comboBox_Ordem->currentText() == "OrdemCrescente" && ui->comboBox_NomesOUNumeros->currentText() == "Nomes"){

            ui->tableWidget_SaidaGrid->setRowCount(objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos());

            int c = 0;

            for (int r=0; r<objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos(); r++){

                pessoa pessoaAux;

                NumerosGrid = (QString::number(objeto.ordenadorPorNome(nomeDoArquivo)[r].getMatricula()));

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NumerosGrid));

            }

            c = 1;

            for (int r=0; r<objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos(); r++){

                NomesGrid = objeto.ordenadorPorNome(nomeDoArquivo)[r].getNome();

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NomesGrid));

            }
        }

        else if (ui->comboBox_Ordem->currentText() == "OrdemCrescente" && ui->comboBox_NomesOUNumeros->currentText() == "Matriculas"){

            ui->tableWidget_SaidaGrid->setRowCount(objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos());

            int c = 0;

            for (int r=0; r<objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos(); r++){

                pessoa pessoaAux;

                NumerosGrid = (QString::number(objeto.ordenadorPorMatricula(nomeDoArquivo)[r].getMatricula()));

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NumerosGrid));

            }

            c = 1;

            for (int r=0; r<objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos(); r++){

                NomesGrid = objeto.ordenadorPorMatricula(nomeDoArquivo)[r].getNome();

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NomesGrid));

            }

        }

        else if (ui->comboBox_Ordem->currentText() == "OrdemDecrescente" && ui->comboBox_NomesOUNumeros->currentText() == "Nomes"){

            ui->tableWidget_SaidaGrid->setRowCount(objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos());

            int c = 0;
            int x = objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos()-1;

            for (int r=0; r<objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos(); r++){


                NumerosGrid = (QString::number(objeto.ordenadorPorNome(nomeDoArquivo)[x].getMatricula()));
                x--;

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NumerosGrid));

            }

            c = 1;
            x = objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos()-1;

            for (int r=0; r<objeto.ordenadorPorNome(nomeDoArquivo).getQuantidadeElementos(); r++){

                NomesGrid = objeto.ordenadorPorNome(nomeDoArquivo)[x].getNome();
                x--;

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NomesGrid));

            }

        }

        else if (ui->comboBox_Ordem->currentText() == "OrdemDecrescente" && ui->comboBox_NomesOUNumeros->currentText() == "Matriculas"){

            ui->tableWidget_SaidaGrid->setRowCount(objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos());

            int c = 0;
            int x = objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos()-1;

            for (int r=0; r<objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos(); r++){


                NumerosGrid = (QString::number(objeto.ordenadorPorMatricula(nomeDoArquivo)[x].getMatricula()));
                x--;

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NumerosGrid));

            }

            c = 1;
            x = objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos()-1;

            for (int r=0; r<objeto.ordenadorPorMatricula(nomeDoArquivo).getQuantidadeElementos(); r++){

                NomesGrid = objeto.ordenadorPorMatricula(nomeDoArquivo)[x].getNome();
                x--;

                ui->tableWidget_SaidaGrid->setItem(r, c, new QTableWidgetItem(NomesGrid));

            }
        }
    }  catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
    catch (std::bad_alloc&) {
            throw QString("Memoria insuficiente");
        }

}

