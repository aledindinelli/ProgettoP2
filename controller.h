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
    unsigned short getEtaPersona(unsigned int i) const;
    unsigned short getOreImpiegato(unsigned int i) const;
    double getPagaImpiegato(unsigned int i) const;
    bool getCattedraDocente(unsigned int i) const;
    QString getRepartoTecnico(unsigned int i) const;
    QString getCorsoStudente(unsigned int i) const;
    bool getRegolareStudente(unsigned int i) const;
    double getMediaStudente(unsigned int i) const;
    QString getRicercaDottorando(unsigned int i) const;
    unsigned short getVotoLaureando(unsigned int i) const;

    tipo getTipoPersona(unsigned int i) const;

    void nuovoDocente(std::string, unsigned short, double, unsigned short, bool);
    void nuovoDottorando(std::string, unsigned short, corsoLaurea, bool, double, std::string);
    void nuovoLaureando(std::string, unsigned short, corsoLaurea, bool, double, unsigned short);
    void nuovoStudLav(std::string, unsigned short, corsoLaurea, bool, double, unsigned short, double);
    void nuovoTecnico(std::string, unsigned short, double, unsigned short, reparto);

    void modificaDocente(std::string, unsigned short, double, unsigned short, bool, unsigned short);

    void resetVettore();
    void cancellaPersona(unsigned short);

private:
    Vista * view;
    Modello * model;
};

#endif // CONTROLLER_H
