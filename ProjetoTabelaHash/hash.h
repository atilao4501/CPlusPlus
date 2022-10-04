#ifndef HASH_H
#define HASH_H
#include <aluno.h>
#include <lldetemplate.h>


class hash
{
private:
    int tam;
    afa::LLDE<int> lista();
public:
    hash();

    int funcaoHash(int chave);
    void inserir(afa::LLDE<aluno> L[],aluno aluno);
    void remover(afa::LLDE<aluno> L[],aluno aluno);
    aluno busca(afa::LLDE<aluno> L[], std::string valor);
    void imprimir(afa::LLDE<aluno> L[]);

    void setTam(int newTam);
};

#endif // HASH_H
