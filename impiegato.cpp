#include "impiegato.h"

Impiegato::Impiegato(std::string n, unsigned short e, unsigned short o) : Persona(n,e), oreLavoro(o) {}

unsigned short Impiegato::getOreLavoro() const
{
    return oreLavoro;
}

void Impiegato::setOreLavoro(unsigned short o)
{
    oreLavoro = o;
}
