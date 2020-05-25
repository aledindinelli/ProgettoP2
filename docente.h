#ifndef DOCENTE_H
#define DOCENTE_H

#include "impiegato.h"

class Docente : public Impiegato
{
private:
    bool cattedra;
    double pagaOraria = 20;
    static double bonusDocente;

public:
    Docente(std::string, unsigned short, unsigned short, bool, double);
    virtual ~Docente() = default;

    bool getCattedra() const;
    void setCattedra(bool);
    double getPagaOraria() const;
    void setPagaOraria(double);

    virtual double costo() const;
    virtual void gestione() ;
};

double Docente::bonusDocente = 300;

#endif // DOCENTE_H
