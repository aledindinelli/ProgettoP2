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

double Docente::costo() const
{
    return getOreLavoro() * getPagaOraria() + cattedra * bonusDocente;
}

void Docente::gestione()
{
    cattedra = true;
    setPagaOraria(1.15);
}
