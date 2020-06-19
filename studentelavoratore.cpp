#include "studentelavoratore.h"

StudenteLavoratore::StudenteLavoratore(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short o, double p)
    : Persona(n,e), Studente(n,e,c,r,m), Impiegato(n,e,o,p) {}

double StudenteLavoratore::salario() const
{
    return Impiegato::salario() + (getRegolare() ? 100 : 0);
}

unsigned short StudenteLavoratore::tasse() const
{
    unsigned short tax = Studente::tasse();
    return tax*3/5;
}

double StudenteLavoratore::costo() const
{
    return salario() - tasse() + rimborso();
}

unsigned short StudenteLavoratore::rimborso() const
{
    return getOreLavoro() * 10;
}

void StudenteLavoratore::migliora()
{
    Studente::migliora();
    setPagaOraria(getPagaOraria() * 1.20);
}
