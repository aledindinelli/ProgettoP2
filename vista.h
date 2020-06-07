#ifndef VISTA_H
#define VISTA_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QFrame>
#include <QMenuBar>
#include <QLineEdit>
#include <QMessageBox>
#include <QLCDNumber>
#include <QPalette>
#include <QButtonGroup>
#include <QPushButton>

class Controller;

class Vista : public QMainWindow
{
    Q_OBJECT

public:
    Vista(Controller *, QWidget *parent = nullptr);

private slots:
    void showGuida();

private:
    Controller * controller;
    QGridLayout * mainLayout;

    void addMenu();
    QGroupBox * addSearch();
    QGroupBox * addLCD();
    QGroupBox * addPersoneBox();
    QGroupBox * addDettagliBox();
};

enum tipo {errore = -1, docente = 0, dottorando = 1, laureando = 2, studentelavoratore = 3, tecnico = 4};
enum corsoLau {inge = 0, inf = 1, psi = 2, eco = 3};

struct DatiPersona
{
    tipo type;
    //Persona
    std::string nome;
    unsigned short eta;
    //Impiegato
    double pagaOraria;
    unsigned short oreLavoro;
    //Docente
    bool cattedra;
    double bonusDocente;
    //Tecnico
    //Studente
    corsoLau corso;
    bool regolare;
    double media;
    //Dottorando
    std::string ricerca;
    //Laureando
    unsigned short votoBase;
    unsigned short bonusVoto;
    //StudenteLavoratore

    DatiPersona(tipo, std::string, unsigned short, double, unsigned short, bool, double, corsoLau, bool, double, std::string, unsigned short, unsigned short);
};

#endif // VISTA_H
