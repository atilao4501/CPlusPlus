#ifndef NO_H
#define NO_H


namespace hlb{
class NO
{
private:
    int dado;
    NO *proximo;
public:
    NO();
    NO(int elemento);
    ~NO();

    int getDado() const;
    void setDado(int newDado);

    NO *getProximo() const;
    void setProximo(NO *newProximo);
};
}
#endif // NO_H

