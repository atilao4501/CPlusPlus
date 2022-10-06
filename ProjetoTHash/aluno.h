#ifndef ALUNO_H
#define ALUNO_H
#include <string>


class aluno
{
private:
    std::string nome;
    std::string mae;
    std::string matricula;
    std::string endereco;

public:
    aluno(std::string gnome, std::string gmae, std::string gmatricula, std::string gendereco);

    const std::string &getNome() const;
    void setNome(const std::string &newNome);
    const std::string &getMae() const;
    void setMae(const std::string &newMae);
    const std::string &getMatricula() const;
    void setMatricula(const std::string &newMatricula);
    const std::string &getEndereco() const;
    void setEndereco(const std::string &newEndereco);
};

#endif // ALUNO_H
