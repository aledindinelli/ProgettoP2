#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "vista.h"
#include "modello.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(Modello *, QObject * parent = nullptr);

    void setView(Vista * v);
    DatiPersona getDatiPersona();
    unsigned int getSize();

public slots:

private:

    Vista * view;
    Modello * model;

};

#endif // CONTROLLER_H
