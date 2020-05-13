#ifndef DOCENTE_H
#define DOCENTE_H

#include "impiegato.h"

class Docente : public Impiegato
{
private:
    bool cattedra;
    static unsigned short pagaOraria;
    static unsigned short bonusDocente;

public:
    Docente(std::string, unsigned short, unsigned short, bool);
    virtual ~Docente();
    virtual unsigned short costo() const;
};

unsigned short Docente::pagaOraria = 20;
unsigned short Docente::bonusDocente = 300;

#endif // DOCENTE_H
