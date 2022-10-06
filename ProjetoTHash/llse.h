#ifndef LLSE_H
#define LLSE_H

#include <no.h>
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
    void inserirInicio(aluno elemento);
    void inserirFim(aluno elemento);


    int getQuantidadeElemento() const;

    aluno retirarInicio();
    aluno retirarFim();

    aluno acessar(int pos);
    aluno retirarQualquer(int pos);

    bool estaVazia() const;
};
}
#endif // LLSE_H
