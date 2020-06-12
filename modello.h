#ifndef MODELLO_H
#define MODELLO_H

#include "vettore.h"
#include "docente.h"
#include "tecnico.h"
#include "laureando.h"
#include "dottorando.h"
#include "studentelavoratore.h"

class Modello
{
private:
    Vettore<Persona *> vett;

public:
    Modello();

    unsigned int getSize() const;
    std::string getNome(unsigned int) const;

    void resetVett();

    void insertDocente(std::string, unsigned short, double, unsigned short, bool);
    void insertDottorando(std::string, unsigned short, corsoLaurea, bool, double, std::string);
    void insertLaureando(std::string, unsigned short, corsoLaurea, bool, double, unsigned short);
    void insertStudLav(std::string, unsigned short, double, unsigned short, corsoLaurea, bool, double);
    void insertTecnico(std::string, unsigned short, double, unsigned short, reparto);

    //funzioni per test
    void popolaVettore()
    {
        Persona* p1 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p2 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p3 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p4 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p5 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p6 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p7 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p8 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p9 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p10 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p11 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p12 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p13 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p14 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p15 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p16 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
        Persona* p17 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);

        vett.push_back(p1);
        vett.push_back(p2);
        vett.push_back(p3);
        vett.push_back(p4);
        vett.push_back(p5);
        vett.push_back(p6);
        vett.push_back(p7);
        vett.push_back(p8);
        vett.push_back(p9);
        vett.push_back(p10);
        vett.push_back(p11);
        vett.push_back(p12);
        vett.push_back(p13);
        vett.push_back(p14);
        vett.push_back(p15);
        vett.push_back(p16);
        vett.push_back(p17);
    }
};

#endif // MODELLO_H
