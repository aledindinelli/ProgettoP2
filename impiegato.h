#ifndef IMPIEGATO_H
#define IMPIEGATO_H

#include "persona.h"

class Impiegato : virtual public Persona
{
private:
    unsigned short oreLavoro;

public:
    Impiegato(std::string, unsigned short, unsigned short);
    virtual ~Impiegato();
    virtual unsigned short getOreLavoro() const;
};

#endif // IMPIEGATO_H
