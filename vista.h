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

class Controller;

class Vista : public QMainWindow
{
    Q_OBJECT

public:
    Vista(Controller*, QWidget *parent = nullptr);

private slots:
    void guida();

private:
    Controller *controller;
    QGridLayout *mainLayout;

    void addMenu();
    QGroupBox *addSearch();
    QGroupBox *addPersoneBox();
    QGroupBox *addDettagliBox();

    void nuovaPersona();
};

#endif // VISTA_H
