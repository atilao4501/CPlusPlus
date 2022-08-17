#ifndef PESSOA_H
#define PESSOA_H

#include <lldetemplate.h>



class pessoa
{
private:
    int Matricula;
    QString Nome;
public:
    pessoa();
    ~pessoa();

    int getMatricula();
    void setMatricula(int elemento);

    QString getNome();
    void setNome(QString elemento);

};

#endif // PESSOA_H
