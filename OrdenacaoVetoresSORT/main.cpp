#include <QCoreApplication>
#include <testaordena.h>
#include <random>

int main()
{
    try {
        int tamanho;
        std::cout << "Insira o tamanho do vetor: ";
        std::cin >> tamanho;

        Itens *vetorPont[tamanho];

        testaordena teste;

        teste.preencherVetor(vetorPont, tamanho);

        std::cout << "Vetor: ";

        for (int pos =0; pos<tamanho; pos++){
            std::cout << vetorPont[pos]->getChave() << ", ";
        }

        int modo;
        std::cout << "\n\n 1-SelectionSort \n 2-InsertionSort \n 3-BubbleSort \n\n Selecione:";
        std::cin >> modo;

        double time_spent = 0.0;

        clock_t begin = clock();

        teste.ordenarVetor(vetorPont,tamanho,modo);

        clock_t end = clock();

        time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

        std::cout << "\nVetor Ordenado: ";

        for (int pos =0; pos<tamanho; pos++){
            std::cout << teste.getVET()[pos]->getChave() << ", ";
        }
        std::cout << "\n";

        printf("\nThe elapsed time is %f seconds", time_spent);
        std::cout << "\n";

    }  catch (std::string erro) {
        std::cout<<"\nERRO NO PROGRAMA: "<<erro<<"\n";

    }
    catch (std::bad_alloc&) {
       std::cout << "Memoria insuficiente";
   }
}


