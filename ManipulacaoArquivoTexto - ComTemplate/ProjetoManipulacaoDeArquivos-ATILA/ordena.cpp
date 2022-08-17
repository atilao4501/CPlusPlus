#include "ordena.h"
#include <QStringList>
#include <string>
#include <vector>
#include <fstream>

namespace afa {

ordena::ordena()
{

}
ordena::~ordena(){

}


afa::LLDE<pessoa> ordena::ordenadorPorNome(QString NomeArquivo){

    std::ifstream arquivo;

    afa::LLDE<pessoa> ListaPessoasOrdenada;

    arquivo.open(NomeArquivo.toStdString().c_str());

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

    QString nome;

    LLDE<QString> auxiliar, auxiliarQString;

    LLDE<pessoa> ListaPessoaAux;

    QStringList AUX;
    QString str = texto;

    AUX = str.split("\n");


    for (int pos = 0; pos < AUX.size(); pos++){

        nome = AUX[pos];
        auxiliar.inserirFim(nome);
    }

    for (int pos = 0; pos < auxiliar.getQuantidadeElementos()-1; pos++){

        QStringList AUX2;
        QString str2, nome2;
        int mat2;

        str2 = auxiliar[pos];

        AUX2 = str2.split(";");

        mat2 = (AUX2[0].toInt());
        nome2 = (AUX2[1]);

        auxiliarQString.inserirOrdenadoCrescente(nome2);

        pessoa pessoaAux;
        pessoaAux.setMatricula(mat2);
        pessoaAux.setNome(nome2);

        ListaPessoaAux.inserirFim(pessoaAux);


    }


    for (int pos = 0; pos < auxiliarQString.getQuantidadeElementos(); pos++){
        int posi = 0;

        pessoa pessoaAux;

        pessoaAux.setNome(auxiliarQString[pos]);

        while (auxiliarQString[pos] != ListaPessoaAux[posi].getNome()){
            posi ++;
        }

        pessoaAux.setMatricula(ListaPessoaAux[posi].getMatricula());

        ListaPessoasOrdenada.inserirFim(pessoaAux);

    }

    return ListaPessoasOrdenada;

}

afa::LLDE<pessoa> ordena::ordenadorPorMatricula(QString NomeArquivo){

    std::ifstream arquivo;

    afa::LLDE<pessoa> ListaPessoasOrdenada;

    arquivo.open(NomeArquivo.toStdString().c_str());

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

    QString nome;

        LLDE<int> auxiliarInteiros;

        LLDE<QString> auxiliar;

        LLDE<pessoa> ListaPessoaAux;

        QStringList AUX;
        QString str = texto;

        AUX = str.split("\n");


        for (int pos = 0; pos < AUX.size(); pos++){

            nome = AUX[pos];
            auxiliar.inserirFim(nome);
        }

        for (int pos = 0; pos < auxiliar.getQuantidadeElementos()-1; pos++){

            QStringList AUX2;
            QString str2, nome2;
            int mat2;

            str2 = auxiliar[pos];

            AUX2 = str2.split(";");

            mat2 = (AUX2[0].toInt());
            nome2 = (AUX2[1]);

            auxiliarInteiros.inserirOrdenadoCrescente(mat2);

            pessoa pessoaAux;
            pessoaAux.setMatricula(mat2);
            pessoaAux.setNome(nome2);

            ListaPessoaAux.inserirFim(pessoaAux);


        }

        for (int pos = 0; pos < auxiliarInteiros.getQuantidadeElementos(); pos++){
            int posi = 0;

            pessoa pessoaAux;

            pessoaAux.setMatricula(auxiliarInteiros[pos]);

            while (auxiliarInteiros[pos] != ListaPessoaAux[posi].getMatricula()){
                posi ++;
            }

            pessoaAux.setNome(ListaPessoaAux[posi].getNome());

            ListaPessoasOrdenada.inserirFim(pessoaAux);

        }

        return ListaPessoasOrdenada;
}

}
