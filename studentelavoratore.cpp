#include "studentelavoratore.h"

StudenteLavoratore::StudenteLavoratore(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short o, double p)
    : Persona(n,e), Studente(n,e,c,r,m), Impiegato(n,e,o,p) {}

unsigned short StudenteLavoratore::tasse() const
{
    unsigned short tax = Studente::tasse();
    return tax*3/5;
}

double StudenteLavoratore::costo() const
{
    return getOreLavoro() * getPagaOraria() - tasse() + rimborso();
}

unsigned short StudenteLavoratore::rimborso() const
{
    return getOreLavoro() * 5;
}

void StudenteLavoratore::gestione()
{
    Studente::gestione();
    setPagaOraria(1.15);
}
