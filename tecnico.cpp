#include "tecnico.h"

Tecnico::Tecnico(std::string n, unsigned short e, unsigned short o)
    : Persona(n,e), Impiegato(n,e,o) {}

Tecnico::~Tecnico() {}

unsigned short Tecnico::costo() const
{
    return getOreLavoro() * pagaOraria;
}
