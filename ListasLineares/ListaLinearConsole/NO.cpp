#include "NO.h"

namespace hlb{
NO::NO():
    dado (0),
    proximo (0)
{
}

NO::NO(int valor):
    dado(valor),
    proximo(0)
{
}

NO::~NO(){
    proximo = 0;
}

int NO::getDado() const
{
    return dado;
}

void NO::setDado(int newDado)
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
