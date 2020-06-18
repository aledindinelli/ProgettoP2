#ifndef STUDENTELAVORATORE_H
#define STUDENTELAVORATORE_H

#include "studente.h"
#include "impiegato.h"

class StudenteLavoratore : public Studente, Impiegato
{
private:

public:
    StudenteLavoratore(std::string, unsigned short, corsoLaurea, bool, double, unsigned short, double);
    virtual ~StudenteLavoratore() = default;

    virtual unsigned short tasse() const;
    virtual double costo() const;
    unsigned short rimborso() const;
    virtual void gestione();
};

#endif // STUDENTELAVORATORE_H
