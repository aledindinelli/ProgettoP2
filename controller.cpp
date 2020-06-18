#include "controller.h"

Controller::Controller(Modello * m, QObject * parent)
    : QObject(parent), view(nullptr), model(m)
{
    model->popolaVettore();
}

void Controller::setView(Vista * v)
{
    view = v;
}

unsigned int Controller::getSize() const
{
    return model->getSize();
}

double Controller::getCosto() const
{
    return model->getCostoTotale();
}

QString Controller::getNomePersona(unsigned int i) const
{
    Persona * p = model->getPersona(i);
    return QString::fromStdString(p->getNome());
}

tipo Controller::getTipoPersona(unsigned int i) const
{
    Persona * p = model->getPersona(i);
    tipo t;
    if (Docente * x = dynamic_cast<Docente *>(p)) {
        t = docente;
    }
    else if (Dottorando * x = dynamic_cast<Dottorando *>(p)) {
        t = dottorando;
    }
    else if (Laureando * x = dynamic_cast<Laureando *>(p)) {
        t = laureando;
    }
    else if (StudenteLavoratore * x = dynamic_cast<StudenteLavoratore *>(p)) {
        t = studlavoratore;
    }
    else if (Tecnico * x = dynamic_cast<Tecnico *>(p)) {
        t = tecnico;
    }
    return t;
}

void Controller::nuovoDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    model->insertDocente(n, e, p, o, c);
}

void Controller::resetVettore()
{
    model->resetVett();
}
