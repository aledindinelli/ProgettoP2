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

double Studente::getMedia() const
{
    return media;
}

void Studente::setCorso(corsoLaurea c)
{
    corso = c;
}

void Studente::setRegolare(bool r)
{
    regolare = r;
}

void Studente::setMedia(double m)
{
    media = m;
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

double Studente::costo() const
{
    if (corso == ingegneria) {
        return 1150 - tasse();
    }
    if (corso == informatica) {
        return 1050 - tasse();
    }
    if (corso == psicologia) {
        return 950 - tasse();
    }
    return 1000 - tasse();
}

void Studente::migliora()
{
    regolare = true;
    if (media < 30) {
        media += 1;
    }
}
