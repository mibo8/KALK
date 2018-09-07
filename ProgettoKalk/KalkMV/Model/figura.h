#ifndef FIGURA_H
#define FIGURA_H
#include <string>
#include "punto.h"

using namespace std;

class Figura {
private:
    string nome;
    static unsigned int id;
public:
    Figura(string);
    string getNome() const;
    void setNome(string);
    unsigned int getId() const;
    virtual double distanza (Figura*) const =0;
    virtual string print() const=0;
    virtual ~Figura() =default;
};

#endif // FIGURA_H
