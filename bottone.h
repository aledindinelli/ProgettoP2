#ifndef BOTTONE_H
#define BOTTONE_H

#include "tipo.h"
#include <QPushButton>

class Bottone : public QPushButton
{
    Q_OBJECT

public:
    Bottone(short int, tipo, QWidget* parent = nullptr);

    short int getIndice();
    tipo getTipo();

private:
    short int indice;
    tipo type;
};

#endif // BOTTONE_H
