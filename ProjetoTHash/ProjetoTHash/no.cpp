#include "no.h"

namespace hlb{
NO::NO(aluno valor):
    dado(valor),
    proximo(0)
{
}

NO::~NO(){
    proximo = 0;
}

aluno NO::getDado() const
{
    return dado;
}

void NO::setDado(aluno newDado)
{
    dado = newDado;
}

NO *NO::getProximo() const
{
    return proximo;
}

void NO::setProximo(NO *newProximo)
{
    proximo = newProximo;
}

}
