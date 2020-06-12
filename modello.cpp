#include "modello.h"

Modello::Modello() {}

std::string Modello::getNome(unsigned int i) const
{
    return vett[i]->getNome();
}

unsigned int Modello::getSize() const
{
    return vett.getSize();
}

void Modello::resetVett()
{
    Vettore<Persona *> temp(0U);
    vett = temp;
}

void Modello::insertDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    Docente * docente = new Docente(n, e, o, c, p);
    vett.push_back(docente);
}

void Modello::insertDottorando(std::string n, unsigned short e, corsoLaurea c, bool reg, double m, std::string ric)
{

}

void Modello::insertLaureando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short v)
{

}

void Modello::insertStudLav(std::string n, unsigned short e, double p, unsigned short o, corsoLaurea c, bool r, double m)
{

}

void Modello::insertTecnico(std::string n, unsigned short e, double p, unsigned short o, reparto r)
{

}
