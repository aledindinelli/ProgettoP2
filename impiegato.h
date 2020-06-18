#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "persona.h"

class Impiegato : virtual public Persona
{
private:
    unsigned short oreLavoro;
    double pagaOraria;

public:
    Impiegato(std::string, unsigned short, unsigned short, double);
    virtual ~Impiegato() = default;

    virtual double getPagaOraria() const;
    virtual void setPagaOraria(double);
    virtual unsigned short getOreLavoro() const;
    virtual void setOreLavoro(unsigned short);
};

#endif // IMPIEGATO_H
