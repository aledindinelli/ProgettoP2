#ifndef STUDENTELAVORATORE_H
#define STUDENTELAVORATORE_H

#include "studente.h"
#include "impiegato.h"

class StudenteLavoratore : public Studente, Impiegato
{
private:
    static unsigned short pagaOraria;

public:
    StudenteLavoratore(std::string, unsigned short, corsoLaurea, bool, unsigned short, unsigned short);
    virtual ~StudenteLavoratore();
    virtual unsigned short tasse() const;
    virtual unsigned short costo() const;
    unsigned short rimborso() const;
};

unsigned short StudenteLavoratore::pagaOraria = 10;

#endif // STUDENTELAVORATORE_H
