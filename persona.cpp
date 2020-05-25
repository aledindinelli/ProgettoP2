#include "persona.h"

Persona::Persona(std::string n, unsigned short e) : nome(n), eta(e) {}

std::string Persona::getNome() const
{
    return nome;
}

unsigned short Persona::getEta() const
{
    return eta;
}

void Persona::setNome(std::string n)
{
    nome = n;
}

void Persona::setEta(unsigned short e)
{
    eta = e;
}
