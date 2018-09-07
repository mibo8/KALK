#include "vettorefigure.h"

VettoreFigure::VettoreFigure(){

}

void VettoreFigure::pushFigura(Figura* pf){
    vFig.push_back(pf);
}
//Metodo che elimina un oggetto Figura* dal vector e distrugge l'oggetto a cui esso punta.
void VettoreFigure::eliminaFigura(Figura* f)
{
    auto it=vFig.begin();
    while(it!=vFig.end()){
        if(*it==f){
            delete *it;
            vFig.erase(it);
        }
        else it++;
    }
}
//ritorna tutte le figure tranne quella passata per parametro, utilizzate nel dialog distanza
vector <Figura*> VettoreFigure::getFigure(Figura* f) const{
    vector <Figura*> r;
    for(auto it=vFig.begin();it!=vFig.end();it++){
        if(f!=(*it)) r.push_back(*it);
    }
    return r;
}

Figura* VettoreFigure::getFiguraByString(string s) const{
    Figura* r;
    for(auto it=vFig.begin();it!=vFig.end();it++){
        if(s==((*it)->getNome())) r=*it;
    }
    return r;
}



