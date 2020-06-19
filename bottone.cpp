#include "bottone.h"

Bottone::Bottone(short int i, tipo t, QWidget *parent) : QPushButton(parent), indice(i) , type(t) {}

short int Bottone::getIndice()
{
    return indice;
}

tipo Bottone::getTipo()
{
    return type;
}
