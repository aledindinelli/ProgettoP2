#include "laureando.h"

unsigned short Laureando::bonusVoto = 100;

Laureando::Laureando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short v)
    : Persona(n,e), Studente(n,e,c,r,m), votoBase(v) {}

unsigned short Laureando::getVotoBase() const
{
    return votoBase;
}

void Laureando::setVotoBase(unsigned short v)
{
    votoBase = v;
}

double Laureando::costo() const
{
    if (votoBase > 28) {
        return Studente::costo() - bonusVoto;
    }
    return Studente::costo();
}

void Laureando::migliora()
{
    Studente::migliora();
    votoBase += 1;
}
