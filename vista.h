#ifndef VISTA_H
#define VISTA_H

#include "dialog.h"
#include "bottone.h"
#include "tipo.h"

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QMenuBar>
#include <QLineEdit>
#include <QMessageBox>
#include <QLCDNumber>
#include <QPushButton>
#include <QScrollArea>
#include <QDialog>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include <QComboBox>

class Controller;

class Vista : public QMainWindow
{
    Q_OBJECT

public:
    Vista(Controller *, QWidget *parent = nullptr);
    void aggiornaApp();
    void showErrorMessage(const QString&);

private slots:
    void showGuida();
    void resetApp();
    void eliminaPersona();
    void upgradePersona();

    void dettagliDocente();
    void dettagliDottorando();
    void dettagliLaureando();
    void dettagliStudLav();
    void dettagliTecnico();

    void addDocente();
    void addDottorando();
    void addLaureando();
    void addStudLav();
    void addTecnico();

    void modificaDocente();
    void modificaDottorando();
    void modificaLaureando();
    void modificaStudLav();
    void modificaTecnico();

private:
    Controller * controller;
    QGridLayout * mainLayout;
    QGroupBox * search;
    QGroupBox * lcd;
    QGroupBox * persone;
    QGroupBox * dettagli;

    void addMenu();
    void addSearch();
    void addLCD();
    void addPersoneBox();
    void addDettagliBox();

    void dettagliPersona(short int, QVBoxLayout *);
    void dettagliImpiegato(short int, QVBoxLayout *);
    void dettagliStudente(short int, QVBoxLayout *);
    void costoPersona(short int, QVBoxLayout *);
};

#endif // VISTA_H
