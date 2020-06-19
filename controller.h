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
    double getCostoPersona(unsigned short) const;

    QString getNomePersona(unsigned short) const;
    unsigned short getEtaPersona(unsigned short) const;
    unsigned short getOreImpiegato(unsigned short) const;
    double getPagaImpiegato(unsigned short) const;
    bool getCattedraDocente(unsigned short) const;
    QString getRepartoTecnico(unsigned short) const;
    QString getCorsoStudente(unsigned short) const;
    bool getRegolareStudente(unsigned short) const;
    double getMediaStudente(unsigned short) const;
    QString getRicercaDottorando(unsigned short) const;
    unsigned short getVotoLaureando(unsigned short) const;
    tipo getTipoPersona(unsigned short) const;

    void nuovoDocente(std::string, unsigned short, double, unsigned short, bool);
    void nuovoDottorando(std::string, unsigned short, unsigned int, bool, double, std::string);
    void nuovoLaureando(std::string, unsigned short, unsigned int, bool, double, unsigned short);
    void nuovoStudLav(std::string, unsigned short, unsigned int, bool, double, unsigned short, double);
    void nuovoTecnico(std::string, unsigned short, double, unsigned short, unsigned int);

    void modificaDocente(QString, unsigned short, double, unsigned short, bool, unsigned short);
    void modificaDottorando(QString, unsigned short, unsigned int, bool, double, QString, unsigned short);
    void modificaLaureando(QString, unsigned short, unsigned int, bool, double, unsigned short, unsigned short);
    void modificaStudLav(QString, unsigned short, double, unsigned short, unsigned int, bool, double, unsigned short);
    void modificaTecnico(QString, unsigned short, double, unsigned short, unsigned int, unsigned short);

    void resetVettore();
    void cancellaPersona(unsigned short);
    void upgradePersona(unsigned short);

private:
    Vista * view;
    Modello * model;
};

#endif // CONTROLLER_H
