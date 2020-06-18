#ifndef TECNICO_H
#define TECNICO_H

#include "impiegato.h"

enum reparto {server = 0, laboratorio = 1, ufficio = 2};

class Tecnico : public Impiegato
{
private:
    reparto settore;

public:
    Tecnico(std::string, unsigned short, unsigned short, reparto, double p = 15);
    virtual ~Tecnico() = default;

    reparto getReparto() const;
    void setReparto(reparto);

    virtual double costo() const;
    virtual void gestione();
};

#endif // TECNICO_H
