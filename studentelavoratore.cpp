#include "studentelavoratore.h"

StudenteLavoratore::StudenteLavoratore(std::string n, unsigned short e, corsoLaurea c, bool r, unsigned short m, unsigned short o)
    : Persona(n,e), Studente(n,e,c,r,m), Impiegato(n,e,o) {}

StudenteLavoratore::~StudenteLavoratore() {}

unsigned short StudenteLavoratore::tasse() const
{
    unsigned short tax = Studente::tasse();
    return tax*3/5;
}

unsigned short StudenteLavoratore::costo() const
{
    return getOreLavoro() * pagaOraria - tasse() + rimborso();
}

unsigned short StudenteLavoratore::rimborso() const
{
    return getOreLavoro() * 5;
}
