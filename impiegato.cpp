#include "impiegato.h"

Impiegato::Impiegato(std::string n, unsigned short e, unsigned short o, double p) : Persona(n,e), oreLavoro(o), pagaOraria(p) {}

double Impiegato::getPagaOraria() const
{
    return pagaOraria;
}

void Impiegato::setPagaOraria(double p)
{
    pagaOraria = p;
}

unsigned short Impiegato::getOreLavoro() const
{
    return oreLavoro;
}

void Impiegato::setOreLavoro(unsigned short o)
{
    oreLavoro = o;
}
