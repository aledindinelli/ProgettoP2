#ifndef STUDENTE_H
#define STUDENTE_H

#include "persona.h"

enum corsoLaurea {ingegneria = 0, informatica = 1, psicologia = 2, economia = 3};

class Studente : virtual public Persona
{
private:
    corsoLaurea corso;
    bool regolare;
    double media;

public:
    Studente(std::string, unsigned short, corsoLaurea, bool, unsigned short);
    virtual ~Studente() = 0;

    virtual corsoLaurea getCorso() const;
    virtual bool getRegolare() const;
    virtual double getMedia() const;

    virtual void setCorso(corsoLaurea);
    virtual void setRegolare(bool);
    virtual void setMedia(double);

    virtual unsigned short tasse() const;
    virtual double costo() const;
    virtual void gestione();
};

#endif // STUDENTE_H
