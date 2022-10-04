#include "aluno.h"

aluno::aluno(std::string gnome, std::string gmae, std::string gmatricula, std::string gendereco)
{
    nome = gnome;
    mae = gmae;
    matricula = gmatricula;
    endereco = gendereco;
}

const std::string &aluno::getNome() const
{
    return nome;
}

void aluno::setNome(const std::string &newNome)
{
    nome = newNome;
}

const std::string &aluno::getMae() const
{
    return mae;
}

void aluno::setMae(const std::string &newMae)
{
    mae = newMae;
}

const std::string &aluno::getMatricula() const
{
    return matricula;
}

void aluno::setMatricula(const std::string &newMatricula)
{
    matricula = newMatricula;
}

const std::string &aluno::getEndereco() const
{
    return endereco;
}

void aluno::setEndereco(const std::string &newEndereco)
{
    endereco = newEndereco;
}


