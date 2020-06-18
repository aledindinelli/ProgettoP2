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

unsigned short Controller::getEtaPersona(unsigned int i) const
{
    Persona * p = model->getPersona(i);
    return p->getEta();
}

unsigned short Controller::getOreImpiegato(unsigned int i) const
{
    Impiegato * p = dynamic_cast <Impiegato *>(model->getPersona(i));
    return p->getOreLavoro();
}

double Controller::getPagaImpiegato(unsigned int i) const
{
    Impiegato * p = dynamic_cast <Impiegato *>(model->getPersona(i));
    return p->getPagaOraria();
}

bool Controller::getCattedraDocente(unsigned int i) const
{
    Docente * p = dynamic_cast <Docente *>(model->getPersona(i));
    return p->getCattedra();
}

QString Controller::getRepartoTecnico(unsigned int i) const
{
    Tecnico * p = dynamic_cast <Tecnico *>(model->getPersona(i));
    reparto s = p->getReparto();
    if (s == server) {
        return QString("Server");
    }
    if (s == laboratorio) {
        return QString("Laboratorio");
    }
    return QString("Ufficio");
}

QString Controller::getCorsoStudente(unsigned int i) const
{
    Studente * p = dynamic_cast <Studente *>(model->getPersona(i));
    corsoLaurea c = p->getCorso();
    if (c == ingegneria) {
        return QString("Ingegneria");
    }
    if (c == informatica) {
        return QString("Informatica");
    }
    if (c == psicologia) {
        return QString("Psicologia");
    }
    return QString("Economia");
}

bool Controller::getRegolareStudente(unsigned int i) const
{
    Studente * p = dynamic_cast <Studente *>(model->getPersona(i));
    return p->getRegolare();
}

double Controller::getMediaStudente(unsigned int i) const
{
    Studente * p = dynamic_cast <Studente *>(model->getPersona(i));
    return p->getMedia();
}

QString Controller::getRicercaDottorando(unsigned int i) const
{
    Dottorando * p = dynamic_cast <Dottorando *>(model->getPersona(i));
    return QString::fromStdString(p->getRicerca());
}

unsigned short Controller::getVotoLaureando(unsigned int i) const
{
    Laureando * p = dynamic_cast <Laureando *>(model->getPersona(i));
    return p->getVotoBase();
}

tipo Controller::getTipoPersona(unsigned int i) const
{
    tipo t;
    if (Docente * x = dynamic_cast<Docente *>(model->getPersona(i))) {
        t = docente;
    }
    if (Dottorando * x = dynamic_cast<Dottorando *>(model->getPersona(i))) {
        t = dottorando;
    }
    if (Laureando * x = dynamic_cast<Laureando *>(model->getPersona(i))) {
        t = laureando;
    }
    if (StudenteLavoratore * x = dynamic_cast<StudenteLavoratore *>(model->getPersona(i))) {
        t = studlavoratore;
    }
    if (Tecnico * x = dynamic_cast<Tecnico *>(model->getPersona(i))) {
        t = tecnico;
    }
    return t;
}

void Controller::nuovoDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    model->insertDocente(n, e, p, o, c);
}

void Controller::nuovoDottorando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, std::string ric)
{
    model->insertDottorando(n, e, c, r, m, ric);
}

void Controller::nuovoLaureando(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short v)
{
    model->insertLaureando(n, e, c, r, m, v);
}

void Controller::nuovoStudLav(std::string n, unsigned short e, corsoLaurea c, bool r, double m, unsigned short o, double p)
{
    model->insertStudLav(n, e, p, o, c, r, m);
}

void Controller::nuovoTecnico(std::string n, unsigned short e, double p, unsigned short o, reparto r)
{
    model->insertTecnico(n, e, p, o, r);

}

void Controller::modificaDocente(std::string n, unsigned short e, double p, unsigned short o, bool c, unsigned short i)
{
    model->modifyDocente(n, e, p, o, c, i);
}

void Controller::resetVettore()
{
    model->resetVett();
}

void Controller::cancellaPersona(unsigned short i)
{
    model->togliPersona(i);
}
