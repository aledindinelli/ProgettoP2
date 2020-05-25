#ifndef TECNICO_H
#define TECNICO_H

#include "impiegato.h"

class Tecnico : public Impiegato
{
private:
    double pagaOraria = 15;

public:
    Tecnico(std::string, unsigned short, unsigned short, double);
    virtual ~Tecnico() = default;

    double getPagaOraria() const;
    void setPagaOraria(double);

    virtual double costo() const;
    virtual void gestione();
};

#endif // TECNICO_H
