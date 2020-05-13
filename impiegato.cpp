#include "impiegato.h"

Impiegato::Impiegato(std::string n, unsigned short e, unsigned short o) : Persona(n,e), oreLavoro(o) {}

Impiegato::~Impiegato() {}

unsigned short Impiegato::getOreLavoro() const
{
    return oreLavoro;
}
