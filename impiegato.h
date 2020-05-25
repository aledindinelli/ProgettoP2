#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "persona.h"

class Impiegato : virtual public Persona
{
private:
    unsigned short oreLavoro;

public:
    Impiegato(std::string, unsigned short, unsigned short);
    virtual ~Impiegato() = default;

    virtual unsigned short getOreLavoro() const;
    virtual void setOreLavoro(unsigned short);
};

#endif // IMPIEGATO_H
