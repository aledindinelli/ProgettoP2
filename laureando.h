#ifndef LAUREANDO_H
#define LAUREANDO_H

#include "studente.h"

class Laureando : public Studente
{
private:
    unsigned short votoBase;
    static unsigned short bonusVoto;

public:
    Laureando(std::string, unsigned short, corsoLaurea, bool, unsigned short, unsigned short);
    virtual unsigned short costo() const;
};

unsigned short Laureando::bonusVoto = 200;

#endif // LAUREANDO_H
