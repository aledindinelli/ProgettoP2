#ifndef DOTTORANDO_H
#define DOTTORANDO_H

#include "studente.h"

class Dottorando : public Studente
{
private:
    std::string ricerca;

public:
    Dottorando(std::string, unsigned short, corsoLaurea, bool, unsigned short, std::string);
    virtual unsigned short tasse() const;
};

#endif // DOTTORANDO_H
