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

    Persona * getPersona(unsigned int) const;
    double getCostoTotale() const;

    void popolaVettore();

    void resetVett();
    void togliPersona(unsigned short);
    void miglioraPersona(unsigned short);

    void insertDocente(std::string, unsigned short, double, unsigned short, bool);
    void insertDottorando(std::string, unsigned short, corsoLaurea, bool, double, std::string);
    void insertLaureando(std::string, unsigned short, corsoLaurea, bool, double, unsigned short);
    void insertStudLav(std::string, unsigned short, double, unsigned short, corsoLaurea, bool, double);
    void insertTecnico(std::string, unsigned short, double, unsigned short, reparto);

    void modifyDocente(std::string, unsigned short, double, unsigned short, bool, unsigned short);
    void modifyDottorando(std::string, unsigned short, corsoLaurea, bool, double, std::string, unsigned short);
    void modifyLaureando(std::string, unsigned short, corsoLaurea, bool, double, unsigned short, unsigned short);
    void modifyStudLav(std::string, unsigned short, double, unsigned short, corsoLaurea, bool, double, unsigned short);
    void modifyTecnico(std::string, unsigned short, double, unsigned short, reparto, unsigned short);
};

#endif // MODELLO_H
