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

QString Controller::getNomePersona(unsigned int i)
{
    return QString::fromStdString(model->getNome(i));
}

unsigned int Controller::getSize()
{
    return model->getSize();
}

void Controller::nuovoDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    model->insertDocente(n, e, p, o, c);
}
