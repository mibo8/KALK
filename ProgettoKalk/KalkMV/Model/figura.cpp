#include "figura.h"

unsigned int Figura::id=1;

Figura::Figura(string s):nome(s){
    id++;
}

string Figura::getNome() const {
    return nome;
}

void Figura::setNome(string s){
    nome=s;
}

unsigned int Figura::getId() const {
    return id;
}
