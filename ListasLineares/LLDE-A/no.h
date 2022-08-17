#ifndef NO_H
#define NO_H
#include <QString>
#include <iostream>

namespace afa{


class NO
{
private:
    int dado;
    NO *proximo;
    NO *anterior;
public:
    NO(int elemento);
    ~NO();

    int getDado() const;
    void setDado(int newDado);

    NO *getProximo() const;
    void setProximo(NO *newProximo);

    NO *getAnterior() const;
    void setAnterior(NO *newAnterior);
};

}
#endif // NO_H

