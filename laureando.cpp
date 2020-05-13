#include "laureando.h"

Laureando::Laureando(std::string n, unsigned short e, corsoLaurea c, bool r, unsigned short m, unsigned short v)
    : Persona(n,e), Studente(n,e,c,r,m), votoBase(v) {}

unsigned short Laureando::costo() const
{
    if (votoBase > 28) {
        return Studente::costo() - bonusVoto;
    }
    return Studente::costo();
}
