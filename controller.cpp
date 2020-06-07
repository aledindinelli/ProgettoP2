#include "controller.h"

Controller::Controller(Modello * m, QObject * parent)
    : QObject(parent), view(nullptr), model(m) {}

void Controller::setView(Vista * v)
{
    view = v;
}

DatiPersona Controller::getDatiPersona()
{

}

unsigned int Controller::getSize()
{
        return model->getSize();

}

