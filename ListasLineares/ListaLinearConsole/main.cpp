#include <iostream>
#include <QString>
#include <LLSE.h>

int main()
{
    hlb::LLSE teste;
    try {
        teste.inserirFim(50);
        teste.inserirInicio(40);
        teste.inserirQualquer(2,60);
        teste.inserirQualquer(0,30);

        std::cout<<"Mostrar Lista: "<<teste.acessar(0)<<"\n";
        std::cout<<"Mostrar Lista: "<<teste.acessar(1)<<"\n";
        std::cout<<"Mostrar Lista: "<<teste.acessar(2)<<"\n";
        std::cout<<"Mostrar Lista: "<<teste.acessar(3)<<"\n";

        std::cout<<"\nRetirar primeiro elemento: "<<teste.retirarInicio();
        std::cout<<"\nRetirar Ultimo Elemento: "<<teste.retirarFim();
        std::cout<<"\nRetirar Elemento na posicao 1: "<<teste.retirarQualquer(1);
        std::cout<<"\nRetirar Primeiro Elemento: "<<teste.retirarInicio();
        std::cout<<"\nRetirar Ultimo Elemento: "<<teste.retirarFim();
    }  catch (QString &erro) {
         std::cout<<"\nERRO NA FILA\n"<<erro.toStdString()<<"\n";
    }
}
