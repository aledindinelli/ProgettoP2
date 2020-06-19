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

double Controller::getCostoPersona(unsigned short i) const
{
    Persona * p = model->getPersona(i);
    return p->costo();
}

QString Controller::getNomePersona(unsigned short i) const
{
    Persona * p = model->getPersona(i);
    return QString::fromStdString(p->getNome());
}

unsigned short Controller::getEtaPersona(unsigned short i) const
{
    Persona * p = model->getPersona(i);
    return p->getEta();
}

unsigned short Controller::getOreImpiegato(unsigned short i) const
{
    Impiegato * p = dynamic_cast <Impiegato *>(model->getPersona(i));
    return p->getOreLavoro();
}

double Controller::getPagaImpiegato(unsigned short i) const
{
    Impiegato * p = dynamic_cast <Impiegato *>(model->getPersona(i));
    return p->getPagaOraria();
}

bool Controller::getCattedraDocente(unsigned short i) const
{
    Docente * p = dynamic_cast <Docente *>(model->getPersona(i));
    return p->getCattedra();
}

QString Controller::getRepartoTecnico(unsigned short i) const
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

QString Controller::getCorsoStudente(unsigned short i) const
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

bool Controller::getRegolareStudente(unsigned short i) const
{
    Studente * p = dynamic_cast <Studente *>(model->getPersona(i));
    return p->getRegolare();
}

double Controller::getMediaStudente(unsigned short i) const
{
    Studente * p = dynamic_cast <Studente *>(model->getPersona(i));
    return p->getMedia();
}

QString Controller::getRicercaDottorando(unsigned short i) const
{
    Dottorando * p = dynamic_cast <Dottorando *>(model->getPersona(i));
    return QString::fromStdString(p->getRicerca());
}

unsigned short Controller::getVotoLaureando(unsigned short i) const
{
    Laureando * p = dynamic_cast <Laureando *>(model->getPersona(i));
    return p->getVotoBase();
}

tipo Controller::getTipoPersona(unsigned short i) const
{
    tipo t;
    if (dynamic_cast<Docente *>(model->getPersona(i))) {
        t = docente;
    }
    if (dynamic_cast<Dottorando *>(model->getPersona(i))) {
        t = dottorando;
    }
    if (dynamic_cast<Laureando *>(model->getPersona(i))) {
        t = laureando;
    }
    if (dynamic_cast<StudenteLavoratore *>(model->getPersona(i))) {
        t = studlavoratore;
    }
    if (dynamic_cast<Tecnico *>(model->getPersona(i))) {
        t = tecnico;
    }
    return t;
}

void Controller::nuovoDocente(std::string n, unsigned short e, double p, unsigned short o, bool c)
{
    model->insertDocente(n, e, p, o, c);
}

void Controller::nuovoDottorando(std::string n, unsigned short e, unsigned int c, bool r, double m, std::string ric)
{
    if (c == 0) {
        model->insertDottorando(n, e, ingegneria, r, m, ric);
    }
    if (c == 1) {
        model->insertDottorando(n, e, informatica, r, m, ric);
    }
    if (c == 2) {
        model->insertDottorando(n, e, psicologia, r, m, ric);
    }
    if (c == 3) {
        model->insertDottorando(n, e, economia, r, m, ric);
    }
}

void Controller::nuovoLaureando(std::string n, unsigned short e, unsigned int c, bool r, double m, unsigned short v)
{
    if (c == 0) {
        model->insertLaureando(n, e, ingegneria, r, m, v);
    }
    if (c == 1) {
        model->insertLaureando(n, e, informatica, r, m, v);
    }
    if (c == 2) {
        model->insertLaureando(n, e, psicologia, r, m, v);
    }
    if (c == 3) {
        model->insertLaureando(n, e, economia, r, m, v);
    }
}

void Controller::nuovoStudLav(std::string n, unsigned short e, unsigned int c, bool r, double m, unsigned short o, double p)
{
    if (c == 0) {
        model->insertStudLav(n, e, p, o, ingegneria, r, m);
    }
    if (c == 1) {
        model->insertStudLav(n, e, p, o, informatica, r, m);
    }
    if (c == 2) {
        model->insertStudLav(n, e, p, o, psicologia, r, m);
    }
    if (c == 3) {
        model->insertStudLav(n, e, p, o, economia, r, m);
    }
}

void Controller::nuovoTecnico(std::string n, unsigned short e, double p, unsigned short o, unsigned int r)
{
    if (r == 0) {
        model->insertTecnico(n, e, p, o, server);
    }
    if (r == 1) {
        model->insertTecnico(n, e, p, o, laboratorio);
    }
    if (r == 2) {
        model->insertTecnico(n, e, p, o, ufficio);
    }
}

void Controller::modificaDocente(QString n, unsigned short e, double p, unsigned short o, bool c, unsigned short i)
{
    model->modifyDocente(n.toStdString(), e, p, o, c, i);
}

void Controller::modificaDottorando(QString n, unsigned short e, unsigned int c, bool reg, double m, QString r, unsigned short i)
{
    if (c == 0) {
        model->modifyDottorando(n.toStdString(), e, ingegneria, reg, m, r.toStdString(), i);
    }
    if (c == 1) {
        model->modifyDottorando(n.toStdString(), e, informatica, reg, m, r.toStdString(), i);
    }
    if (c == 2) {
        model->modifyDottorando(n.toStdString(), e, psicologia, reg, m, r.toStdString(), i);
    }
    if (c == 3) {
        model->modifyDottorando(n.toStdString(), e, economia, reg, m, r.toStdString(), i);
    }
}

void Controller::modificaLaureando(QString n, unsigned short e, unsigned int c, bool reg, double m, unsigned short v, unsigned short i)
{
    if (c == 0) {
        model->modifyLaureando(n.toStdString(), e, ingegneria, reg, m, v, i);
    }
    if (c == 1) {
        model->modifyLaureando(n.toStdString(), e, informatica, reg, m, v, i);
    }
    if (c == 2) {
        model->modifyLaureando(n.toStdString(), e, psicologia, reg, m, v, i);
    }
    if (c == 3) {
        model->modifyLaureando(n.toStdString(), e, economia, reg, m, v, i);
    }
}

void Controller::modificaStudLav(QString n, unsigned short e, double p, unsigned short o, unsigned int c, bool reg, double m, unsigned short i)
{
    if (c == 0) {
        model->modifyStudLav(n.toStdString(), e, p, o, ingegneria, reg, m, i);
    }
    if (c == 1) {
        model->modifyStudLav(n.toStdString(), e, p, o, informatica, reg, m, i);
    }
    if (c == 2) {
        model->modifyStudLav(n.toStdString(), e, p, o, psicologia, reg, m, i);
    }
    if (c == 3) {
        model->modifyStudLav(n.toStdString(), e, p, o, economia, reg, m, i);
    }
}

void Controller::modificaTecnico(QString n, unsigned short e, double p, unsigned short o, unsigned int r, unsigned short i)
{
    if (r == 0) {
        model->modifyTecnico(n.toStdString(), e, p, o, server, i);
    }
    if (r == 1) {
        model->modifyTecnico(n.toStdString(), e, p, o, laboratorio, i);
    }
    if (r == 2) {
        model->modifyTecnico(n.toStdString(), e, p, o, ufficio, i);
    }
}

void Controller::resetVettore()
{
    model->resetVett();
}

void Controller::cancellaPersona(unsigned short i)
{
    model->togliPersona(i);
}

void Controller::upgradePersona(unsigned short i)
{
    model->miglioraPersona(i);
}
