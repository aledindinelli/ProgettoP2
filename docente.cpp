#include "docente.h"

Docente::Docente(std::string n, unsigned short e, unsigned short o, bool c)
    : Persona(n,e), Impiegato(n,e,o), cattedra(c) {}

unsigned short Docente::costo() const
{
    return getOreLavoro() * pagaOraria + cattedra * bonusDocente;
}
