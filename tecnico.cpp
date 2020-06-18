#include "tecnico.h"

Tecnico::Tecnico(std::string n, unsigned short e, unsigned short o, reparto s, double p)
    : Persona(n,e), Impiegato(n,e,o,p), settore(s) {}

reparto Tecnico::getReparto() const
{
    return  settore;
}

void Tecnico::setReparto(reparto r)
{
    settore = r;
}


double Tecnico::costo() const
{
    return getOreLavoro() * getPagaOraria();
}

void Tecnico::gestione()
{
    setPagaOraria(1.15);
}
