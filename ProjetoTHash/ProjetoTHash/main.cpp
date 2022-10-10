#include <QCoreApplication>
#include <aluno.h>
#include <testahash.h>
#include <iostream>

int main()
{
    try {
        int tamanho;
        std::cout << "Insira o tamanho: ";
        std::cin >> tamanho;
        testaHash teste(tamanho);
        teste.principal();


    }  catch (std::string erro) {
        std::cout<<"\nERRO NO PROGRAMA: "<<erro<<"\n";

    }




}
