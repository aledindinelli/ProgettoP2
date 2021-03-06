#include "dottorando.h"

Dottorando::Dottorando(std::string n, unsigned short e, corsoLaurea c, bool r, unsigned short m, std::string ric)
    : Persona(n,e), Studente(n,e,c,r,m), ricerca(ric) {}

std::string Dottorando::getRicerca() const
{
    return ricerca;
}

void Dottorando::setRicerca(std::string r)
{
    ricerca = r;
}

unsigned short Dottorando::tasse() const
{
    unsigned short tax = Studente::tasse();
    return tax*2/3;
}

