#include "controller.h"

Controller::Controller(Modello* m, QObject *parent)
    : QObject(parent), view(nullptr), model(m) {}

void Controller::setView(Vista *v)
{
    view = v;
}

//void Controller::resetApp()
//{
//    model->resetVett();
//    view->resetVista();
//}
