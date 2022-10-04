#ifndef NOTEMPLATE_H
#define NOTEMPLATE_H

#include <QString>
#include <iostream>
#include <string>

namespace afa{

template<typename T>

class NO
{
private:
    T dado;
    NO *proximo;
    NO *anterior;
public:
    NO(T elemento);
    ~NO();

    T getDado() const;
    void setDado(T newDado);

    NO *getProximo() const;
    void setProximo(NO *newProximo);

    NO *getAnterior() const;
    void setAnterior(NO *newAnterior);
};

template<typename T>
NO<T>::NO(T valor):
    dado(valor),
    proximo(0),
    anterior(0)
{
}
template<typename T>
NO<T>::~NO(){
    proximo = 0;
    anterior = 0;
}
template<typename T>
T NO<T>::getDado() const
{
    return dado;
}

template<typename T>
void NO<T>::setDado(T newDado)
{
    dado = newDado;
}

template<typename T>
NO<T> *NO<T>::getProximo() const
{
    return proximo;
}

template<typename T>
void NO<T>::setProximo(NO *newProximo)
{
    proximo = newProximo;
}
template<typename T>
NO<T> *NO<T>::getAnterior() const
{
    return anterior;
}

template<typename T>
void NO<T>::setAnterior(NO *newAnterior)
{
    anterior = newAnterior;
}



}

#endif // NOTEMPLATE_H
