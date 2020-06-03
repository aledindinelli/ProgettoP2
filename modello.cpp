#include "modello.h"

Modello::Modello() {}

void Modello::resetVett()
{
    Vettore<Persona*> temp(0U);
    vett = temp;
}

void Modello::popolaVettore()
{
    Persona* p1 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p2 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p3 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p4 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p5 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p6 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
    Persona* p7 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);

    vett.push_back(p1);
    vett.push_back(p2);
    vett.push_back(p3);
    vett.push_back(p4);
    vett.push_back(p5);
    vett.push_back(p6);
    vett.push_back(p7);
}

void Modello::leggiVettore(const Vettore<Persona *> & v)
{
    Laureando * ptr;
    for (Vettore<Persona*>::ConstIteratore cit = v.citBegin(); cit != v.citEnd(); ++cit)
    {
        ptr = dynamic_cast<Laureando *>(cit);
        cout << cit.getNome() << " " << cit.getEta() << endl;
    }
}
