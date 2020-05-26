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
    Vettore<Persona*> V;

public:
    Modello();
};

#endif // MODELLO_H
