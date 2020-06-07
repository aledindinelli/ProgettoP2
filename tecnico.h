#ifndef TECNICO_H
#define TECNICO_H

#include "impiegato.h"

class Tecnico : public Impiegato
{
private:

public:
    Tecnico(std::string, unsigned short, unsigned short, double p = 15);
    virtual ~Tecnico() = default;

    virtual double costo() const;
    virtual void gestione();
};

#endif // TECNICO_H
