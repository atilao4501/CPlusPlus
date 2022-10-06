#ifndef HASH_H
#define HASH_H
#include <aluno.h>
#include <llse.h>


class hash
{
private:
    int tam;
    hlb::LLSE *tabela;
public:
    hash(int tamanho);
    ~hash();

    int funcaoHash(int chave);
    void inserir(aluno aluno);

    aluno busca(std::string nome,std::string mae,std::string mat);
    bool remover(std::string nome,std::string mae,std::string mat);
    void imprimir();

    void setTam(int newTam);
};

#endif // HASH_H
