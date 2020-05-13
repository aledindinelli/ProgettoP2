#ifndef TECNICO_H
#define TECNICO_H

#include "impiegato.h"

class Tecnico : public Impiegato
{
private:
    static unsigned short pagaOraria;

public:
    Tecnico(std::string, unsigned short, unsigned short);
    virtual ~Tecnico();
    virtual unsigned short costo() const;
};

unsigned short Tecnico::pagaOraria = 15;

#endif // TECNICO_H
