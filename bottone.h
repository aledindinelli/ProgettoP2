#ifndef BOTTONE_H
#define BOTTONE_H

#include <QPushButton>
#include "tipo.h"

class Bottone : public QPushButton
{
    Q_OBJECT

public:
    Bottone(unsigned short, tipo, QWidget* parent = nullptr);

    unsigned short getIndice();
    tipo getTipo();

private:
    unsigned short indice;
    tipo type;
};

#endif // BOTTONE_H
