#include "persona.h"

Persona::Persona(std::string n, unsigned short e) : nome(n), eta(e) {}

Persona::~Persona() {}

std::string Persona::getNome() const
{
    return nome;
}

unsigned short Persona::getEta() const
{
    return eta;
}
