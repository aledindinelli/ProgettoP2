#include "studentelavoratore.h"

StudenteLavoratore::StudenteLavoratore(std::string n, unsigned short e, corsoLaurea c, bool r, unsigned short m, unsigned short o, double p)
    : Persona(n,e), Studente(n,e,c,r,m), Impiegato(n,e,o), pagaOraria(p) {}

unsigned short StudenteLavoratore::tasse() const
{
    unsigned short tax = Studente::tasse();
    return tax*3/5;
}

double StudenteLavoratore::costo() const
{
    return getOreLavoro() * pagaOraria - tasse() + rimborso();
}

unsigned short StudenteLavoratore::rimborso() const
{
    return getOreLavoro() * 5;
}

void StudenteLavoratore::gestione()
{
    Studente::gestione();
    pagaOraria *= 1.15;
}
