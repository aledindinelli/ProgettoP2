#include "modello.h"

Modello::Modello() : vett(0U) {}

unsigned int Modello::getSize() const
{
    return vett.getSize();
}

Persona * Modello::getPersona(unsigned int i) const
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
    Persona* p1 = new Laureando("Paolo Rossi", 18, ingegneria, false, 25, 90);
    Persona* p2 = new Docente("Sara Bianchi", 50, 30, true, 25);
    Persona* p3 = new StudenteLavoratore("Andrea Mario", 24, ingegneria, true, 25, 15, 15);
    Persona* p4 = new Tecnico("Bobo Vieri", 45, 30, ufficio, 20);
    Persona* p5 = new Dottorando("Carla Bruni", 28, economia, true, 26, "Economia Internazionale");
    Persona* p6 = new Docente("Gigi Buffon", 55, 40, false, 20);
    Persona* p7 = new StudenteLavoratore("Mattia Verdi", 20, economia, false, 23, 20, 15);
    Persona* p8 = new Laureando("Giulio Cesare", 20, informatica, true, 28, 100);
    Persona* p9 = new Dottorando("Luigi Bruni", 29, psicologia, false, 20, "Psicanalisi");
    Persona* p10 = new Tecnico("Silvia Rossi", 40, 25, server, 15);

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

void Modello::miglioraPersona(unsigned short i)
{
    Vettore<Persona *>::Iteratore it = vett.itBegin();
    for (unsigned int j=0; j<i; j++) {
        ++it;
    }
    (*it)->migliora();
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
    Docente * x = dynamic_cast<Docente *>(getPersona(i));
    x->setNome(n);
    x->setEta(e);
    x->setPagaOraria(p);
    x->setOreLavoro(o);
    x->setCattedra(c);
}

void Modello::modifyDottorando(std::string n, unsigned short e, corsoLaurea c, bool reg, double m, std::string r, unsigned short i)
{
    Dottorando * x = dynamic_cast<Dottorando *>(getPersona(i));
    x->setNome(n);
    x->setEta(e);
    x->setCorso(c);
    x->setRegolare(reg);
    x->setMedia(m);
    x->setRicerca(r);
}

void Modello::modifyLaureando(std::string n, unsigned short e, corsoLaurea c, bool reg, double m, unsigned short v, unsigned short i)
{
    Laureando * x = dynamic_cast<Laureando *>(getPersona(i));
    x->setNome(n);
    x->setEta(e);
    x->setCorso(c);
    x->setRegolare(reg);
    x->setMedia(m);
    x->setVotoBase(v);
}

void Modello::modifyStudLav(std::string n, unsigned short e, double p, unsigned short o, corsoLaurea c, bool reg, double m, unsigned short i)
{
    StudenteLavoratore * x = dynamic_cast<StudenteLavoratore *>(getPersona(i));
    x->setNome(n);
    x->setEta(e);
    x->setPagaOraria(p);
    x->setOreLavoro(o);
    x->setCorso(c);
    x->setRegolare(reg);
    x->setMedia(m);
}

void Modello::modifyTecnico(std::string n, unsigned short e, double p, unsigned short o, reparto r, unsigned short i)
{
    Tecnico * x = dynamic_cast<Tecnico *>(getPersona(i));
    x->setNome(n);
    x->setEta(e);
    x->setPagaOraria(p);
    x->setOreLavoro(o);
    x->setReparto(r);
}


