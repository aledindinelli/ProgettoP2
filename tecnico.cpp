#include "tecnico.h"

Tecnico::Tecnico(std::string n, unsigned short e, unsigned short o, double p)
    : Persona(n,e), Impiegato(n,e,o), pagaOraria(p) {}

double Tecnico::getPagaOraria() const
{
    return pagaOraria;
}

void Tecnico::setPagaOraria(double p)
{
    pagaOraria = p;
}

double Tecnico::costo() const
{
    return getOreLavoro() * pagaOraria;
}

void Tecnico::gestione()
{
    pagaOraria *= 1.15;
}
