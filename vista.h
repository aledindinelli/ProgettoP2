#ifndef VISTA_H
#define VISTA_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
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

private slots:
    void showGuida();
    void addDocente();
    void addDottorando();
    void addLaureando();
    void addStudLav();
    void addTecnico();
    void creaDocente(QString, unsigned int, double, unsigned int, bool);

private:
    Controller * controller;
    QGridLayout * mainLayout;

    void addMenu();
    QGroupBox * addSearch();
    QGroupBox * addLCD();
    QGroupBox * addPersoneBox();
    QGroupBox * addDettagliBox();
};

#endif // VISTA_H
