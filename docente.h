#ifndef DOCENTE_H
#define DOCENTE_H

#include "impiegato.h"

class Docente : public Impiegato
{
private:
    bool cattedra;
    static double bonusDocente;

public:
    Docente(std::string, unsigned short, unsigned short, bool, double p = 20);
    virtual ~Docente() = default;

    bool getCattedra() const;
    void setCattedra(bool);

    virtual double salario() const;
    virtual double costo() const;
    virtual void migliora();
};

#endif // DOCENTE_H
