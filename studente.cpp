#include "studente.h"

Studente::Studente(std::string n, unsigned short e, corsoLaurea c, bool r, unsigned short m) : Persona(n,e), corso(c), regolare(r), media(m) {}

Studente::~Studente() {}

corsoLaurea Studente::getCorso() const
{
    return corso;
}

bool Studente::getRegolare() const
{
    return regolare;
}

unsigned short Studente::getMedia() const
{
    return media;
}

unsigned short Studente::tasse() const
{
    unsigned short tot = 1100;
    if (media > 28) {
        tot = 800;
    }
    if (getRegolare()) {
        tot -= 100;
    }
    else {
        tot +=150;
    }
    return tot;
}

unsigned short Studente::costo() const
{
    switch (corso) {
    case ingegneria: return 900 - tasse();
    case informatica: return 850 - tasse();
    case psicologia: return 800 - tasse();
    case economia: return 950 - tasse();
    }
}