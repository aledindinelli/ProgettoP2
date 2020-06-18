#include "bottone.h"

Bottone::Bottone(unsigned short i, tipo t, QWidget *parent) : QPushButton(parent), indice(i) , type(t) {}

unsigned short Bottone::getIndice()
{
    return indice;
}

tipo Bottone::getTipo()
{
    return type;
}
