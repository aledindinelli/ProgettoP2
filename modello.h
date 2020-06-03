#ifndef MODELLO_H
#define MODELLO_H

#include "vettore.h"
#include "docente.h"
#include "tecnico.h"
#include "laureando.h"
#include "dottorando.h"
#include "studentelavoratore.h"

//per test
#include <iostream>
using namespace std;

class Modello
{
private:


public:
    Vettore<Persona*> vett;
    Modello();

    void resetVett();

    //per test
    void popolaVettore();
    void leggiVettore(const Vettore<Persona *> &);
};

#endif // MODELLO_H
