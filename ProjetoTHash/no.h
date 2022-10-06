#ifndef NO_H
#define NO_H
#include <aluno.h>


namespace hlb{
class NO
{
private:
    aluno dado;
    NO *proximo;
public:
    NO(aluno elemento);
    ~NO();

    aluno getDado() const;
    void setDado(aluno newDado);

    NO *getProximo() const;
    void setProximo(NO *newProximo);
};
}
#endif // NO_H

