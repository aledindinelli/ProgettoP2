#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "vista.h"
#include "modello.h"
#include "tipo.h"

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(Modello *, QObject * parent = nullptr);

    void setView(Vista * v);

    unsigned int getSize() const;
    double getCosto() const;

    QString getNomePersona(unsigned int i) const;
    tipo getTipoPersona(unsigned int i) const;

    void nuovoDocente(std::string, unsigned short, double, unsigned short, bool);

    void resetVettore();

private:
    Vista * view;
    Modello * model;
};

#endif // CONTROLLER_H
