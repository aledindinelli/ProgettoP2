#include "modello.h"

Modello::Modello() : vett(0U) {}

unsigned int Modello::getSize() const
{
    return vett.getSize();
}

Persona *Modello::getPersona(unsigned int i) const
{
    return vett[i];
}

double Modello::getCostoTotale() const
{
    double costo = 0;
    for (Vettore<Persona *>::ConstIteratore cit = vett.citBegin(); cit != vett.citEnd(); ++cit) {
        costo += (*cit)->costo();
    }
    return costo;
}

void Modello::popolaVettore()
{
//    Persona* p1 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p2 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p3 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p4 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p5 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p6 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p7 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p8 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p9 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p10 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p11 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p12 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p13 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p14 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p15 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p16 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);
//    Persona* p17 = new Laureando("Paolo Rossi", 30, ingegneria, false, 25, 90);

//    vett.push_back(p1);
//    vett.push_back(p2);
//    vett.push_back(p3);
//    vett.push_back(p4);
//    vett.push_back(p5);
//    vett.push_back(p6);
//    vett.push_back(p7);
//    vett.push_back(p8);
//    vett.push_back(p9);
//    vett.push_back(p10);
//    vett.push_back(p11);
//    vett.push_back(p12);
//    vett.push_back(p13);
//    vett.push_back(p14);
//    vett.push_back(p15);
//    vett.push_back(p16);
//    vett.push_back(p17);
}

void Modello::resetVett()
{
    Vettore<Persona *> temp(0U);
    vett = temp;
}

void Modello::togliPersona(unsigned short i)
{
    Vettore<Persona *>::Iteratore it = vett.itBegin();
    for (unsigned int j=0; j<i; j++) {
        ++it;
    }
    vett.erase(it);
}

void Modello::insertDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    Docente * docente = new Docente(n, e, o, c, p);
    vett.push_back(docente);
}

void Modello::insertDottorando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, std::string ric)
{
    Dottorando * dottorando = new Dottorando(n, e, c, r, m, ric);
    vett.push_back(dottorando);
}

void Modello::insertLaureando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short v)
{
    Laureando * laureando = new Laureando(n, e, c, r, m, v);
    vett.push_back(laureando);
}

void Modello::insertStudLav(std::string n, unsigned short e, double p, unsigned short o, corsoLaurea c, bool r, double m)
{
    StudenteLavoratore * studLav = new StudenteLavoratore(n, e, c, r, m, o, p);
    vett.push_back(studLav);
}

void Modello::insertTecnico(std::string n, unsigned short e, double p, unsigned short o, reparto r)
{
    Tecnico * tecnico = new Tecnico(n, e, o, r, p);
    vett.push_back(tecnico);
}

void Modello::modifyDocente(std::string n, unsigned short e, double p, unsigned short o, bool c, unsigned short i)
{
    Vettore<Persona *>::Iteratore it = vett.itBegin();
    for (unsigned int j=0; j<i; j++) {
        ++it;
    }
    Docente * x = dynamic_cast<Docente *>(*it);
    x->setNome(n);
    x->setEta(e);
    x->setPagaOraria(p);
    x->setOreLavoro(o);
    x->setCattedra(c);
}
