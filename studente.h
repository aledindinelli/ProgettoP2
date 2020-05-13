#ifndef STUDENTE_H
#define STUDENTE_H

#include "persona.h"

enum corsoLaurea {ingegneria = 0, informatica = 1, psicologia = 2, economia = 3};

class Studente : virtual public Persona
{
private:
    corsoLaurea corso;
    bool regolare;
    unsigned short media;

public:
    Studente(std::string, unsigned short, corsoLaurea, bool, unsigned short);
    virtual ~Studente();
    virtual corsoLaurea getCorso() const;
    virtual bool getRegolare() const;
    virtual unsigned short getMedia() const;
    virtual unsigned short tasse() const;
    virtual unsigned short costo() const;
};

#endif // STUDENTE_H
