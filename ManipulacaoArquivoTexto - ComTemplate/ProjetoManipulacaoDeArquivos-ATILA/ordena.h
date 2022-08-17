#ifndef ORDENA_H
#define ORDENA_H
#include "lldetemplate.h"
#include <iostream>
#include <string>
#include <vector>
#include <pessoa.h>

namespace afa {
class ordena
{
private:  

public:
    ordena();
    ~ordena();

    afa::LLDE<pessoa> ordenadorPorNome(QString NomeArquivo);
    afa::LLDE<pessoa> ordenadorPorMatricula(QString NomeArquivo);

};
}

#endif // ORDENA_H
