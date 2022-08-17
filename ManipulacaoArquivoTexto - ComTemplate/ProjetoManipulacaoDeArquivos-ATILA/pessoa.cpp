#include "pessoa.h"

pessoa::pessoa()
{

}
pessoa::~pessoa(){

}
void pessoa::setMatricula(int elemento){
    Matricula = elemento;
}
int pessoa::getMatricula(){
    return Matricula;
}
void pessoa::setNome(QString elemento){
    Nome = elemento;
}
QString pessoa::getNome(){
    return Nome;
}
