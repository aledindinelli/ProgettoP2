#include "docente.h"

Docente::Docente(std::string n, unsigned short e, unsigned short o, bool c, double p)
    : Persona(n,e), Impiegato(n,e,o), cattedra(c), pagaOraria(p) {}

bool Docente::getCattedra() const
{
    return cattedra;
}

void Docente::setCattedra(bool c)
{
    cattedra = c;
}

double Docente::getPagaOraria() const
{
    return pagaOraria;
}

void Docente::setPagaOraria(double p)
{
    pagaOraria = p;
}

double Docente::costo() const
{
    return getOreLavoro() * pagaOraria + cattedra * bonusDocente;
}

void Docente::gestione()
{
    cattedra = true;
    pagaOraria *= 1.15;
}
