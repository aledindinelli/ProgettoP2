#include "modello.h"

Modello::Modello() : vett(0U) {}

unsigned int Modello::getSize() const
{
    return vett.getSize();
}

Persona *Modello::getPersona(unsigned int i) const
{
    return vett[i];
}

double Modello::getCostoTotale() const
{
    double costo = 0;
    for (Vettore<Persona *>::ConstIteratore cit = vett.citBegin(); cit != vett.citEnd(); ++cit) {
        costo += (*cit)->costo();
    }
    return costo;
}

void Modello::resetVett()
{
    Vettore<Persona *> temp(0U);
    vett = temp;
}

void Modello::insertDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    Docente * docente = new Docente(n, e, o, c, p);
    vett.push_back(docente);
}

void Modello::insertDottorando(std::string n, unsigned short e, corsoLaurea c, bool reg, double m, std::string ric)
{
//    Docente * dottorando = new Dottorando(n, e,);
//    vett.push_back(dottorando);
}

void Modello::insertLaureando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short v)
{
//    Docente * laureando = new Laureando(n, e,);
//    vett.push_back(laureando);
}

void Modello::insertStudLav(std::string n, unsigned short e, double p, unsigned short o, corsoLaurea c, bool r, double m)
{
//    Docente * studLav = new StudenteLavoratore(n, e,);
//    vett.push_back(studLav);
}

void Modello::insertTecnico(std::string n, unsigned short e, double p, unsigned short o, reparto r)
{
//    Docente * tecnico = new Tecnico(n, e, o, r, p);
//    vett.push_back(tecnico);
}
