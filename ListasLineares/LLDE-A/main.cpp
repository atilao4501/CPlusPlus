#include <QCoreApplication>
#include <llde.h>

int main()
{
    try {
        afa::LLDE teste;

        //teste inserirGeral

        /*teste.inserirInicio(30);
        teste.inserirInicio(20);
        teste.inserirInicio(10);

        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();

        std::cout << "\n\n Retirando do fim agora: ";

        teste.inserirFim(10);
        teste.inserirFim(20);
        teste.inserirFim(30);

        std::cout << "\n Numero retirado: " << teste.retirarFim();
        std::cout << "\n Numero retirado: " << teste.retirarFim();
        std::cout << "\n Numero retirado: " << teste.retirarFim();

        std::cout << "\n\n Retirando Inicio e fim: ";

        teste.inserirInicio(30);
        teste.inserirFim(40);
        teste.inserirInicio(10);
        teste.inserirFim(20);

        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarFim();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarFim();*/

        //teste inserir ordenado.

        /*teste.inserirOrdenadoCrescente(2);
        teste.inserirOrdenadoCrescente(1);
        teste.inserirOrdenadoCrescente(5);
        teste.inserirOrdenadoCrescente(3);
        teste.inserirOrdenadoCrescente(6);
        teste.inserirOrdenadoCrescente(4);

        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();*/

        //teste acessar

        teste.inserirInicio(2);
        teste.inserirFim(4);
        teste.inserirPos(0, 1);
        teste.inserirOrdenadoCrescente(3);

        std::cout << "\n Numero acessado: " << teste[0];
        std::cout << "\n Numero acessado: " << teste[1];
        std::cout << "\n Numero acessado: " << teste[2];
        std::cout << "\n Numero acessado: " << teste[3];

        std::cout << "\n\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarPos(2);
        std::cout << "\n Numero retirado: " << teste.retirarFim();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();
        std::cout << "\n Numero retirado: " << teste.retirarInicio();




    }  catch (QString &erro) {
         std::cout<<"\nERRO NA FILA\n"<<erro.toStdString()<<"\n";
    }


}
