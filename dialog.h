#ifndef DIALOG_H
#define DIALOG_H

#include "tipo.h"
#include "bottone.h"

//togliere roba inutile
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
#include <QButtonGroup>
#include <QPushButton>
#include <QScrollArea>
#include <QDialog>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QRadioButton>
#include <QComboBox>

class Controller;
class Vista;

class Dialog : public QDialog
{
    Q_OBJECT

    friend Vista;

private slots:
    void creaDocente();
    void creaDottorando();
    void creaLaureando();
    void creaStudLav();
    void creaTecnico();

private:
    Controller * controller;
    Vista * vista;

    QFormLayout * layout;
    QLineEdit * nome;
    QSpinBox * eta;
    QDoubleSpinBox * paga;
    QSpinBox * ore;
    QRadioButton * cattSi;
    QRadioButton * cattNo;
    QComboBox * corso;
    QRadioButton * regSi;
    QRadioButton * regNo;
    QDoubleSpinBox * media;
    QLineEdit * ricerca;
    QSpinBox * votoBase;
    QSpinBox * bonusVoto;
    QComboBox * reparto;
    Bottone * invio;

public:
    Dialog(Controller *, Vista *, tipo, QWidget * parent = nullptr);
};

#endif // DIALOG_H
