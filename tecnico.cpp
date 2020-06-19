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

double Tecnico::salario() const
{
    return Impiegato::salario() + (getOreLavoro() > 15 ? 75 : 25);
}

double Tecnico::costo() const
{
    if (settore == server) {
        return salario() + 100;
    }
    if (settore == laboratorio) {
        return salario() + 75;
    }
    return salario() + 50;
}

void Tecnico::migliora()
{
    setPagaOraria(getPagaOraria() * 1.25);
}
