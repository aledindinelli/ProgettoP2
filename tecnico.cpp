#include "tecnico.h"

Tecnico::Tecnico(std::string n, unsigned short e, unsigned short o, double p)
    : Persona(n,e), Impiegato(n,e,o,p) {}


double Tecnico::costo() const
{
    return getOreLavoro() * getPagaOraria();
}

void Tecnico::gestione()
{
    setPagaOraria(1.15);
}
