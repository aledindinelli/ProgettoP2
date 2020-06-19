#ifndef LAUREANDO_H
#define LAUREANDO_H

#include "studente.h"

class Laureando : public Studente
{
private:
    unsigned short votoBase;
    static unsigned short bonusVoto;

public:
    Laureando(std::string, unsigned short, corsoLaurea, bool, double, unsigned short);
    virtual ~Laureando() = default;

    unsigned short getVotoBase() const;
    void setVotoBase(unsigned short);

    virtual double costo() const;
    virtual void migliora();
};

#endif // LAUREANDO_H
