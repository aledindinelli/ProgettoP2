#include "docente.h"

double Docente::bonusDocente = 300;

Docente::Docente(std::string n, unsigned short e, unsigned short o, bool c, double p)
    : Persona(n,e), Impiegato(n,e,o,p), cattedra(c) {}

bool Docente::getCattedra() const
{
    return cattedra;
}

void Docente::setCattedra(bool c)
{
    cattedra = c;
}

double Docente::salario() const
{
    return Impiegato::salario() + cattedra * bonusDocente;
}

double Docente::costo() const
{
    return salario() + (getOreLavoro() > 20 ? 100 : 0);
}

void Docente::migliora()
{
    cattedra = true;
    setPagaOraria(getPagaOraria() * 1.5);
}
