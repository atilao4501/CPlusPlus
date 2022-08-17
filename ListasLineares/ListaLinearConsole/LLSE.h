#ifndef LLSE_H
#define LLSE_H

#include <NO.h>
#include <QString>

namespace hlb{
class LLSE
{
private:
    NO *inicio;
    int quantidadeElemento;
public:
    LLSE();
    ~LLSE();
    void inserirInicio(int elemento);
    void inserirFim(int elemento);
    void inserirQualquer(int pos, int elemento);

    int getQuantidadeElemento() const;

    int retirarInicio();
    int retirarFim();

    int acessar(int pos);
    int retirarQualquer(int pos);

    bool estaVazia() const;
};
}
#endif // LLSE_H
