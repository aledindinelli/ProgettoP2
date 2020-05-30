#include "vista.h"

Vista::Vista(Controller* c, QWidget *parent) : QMainWindow(parent), controller(c)
{
    setWindowTitle(tr("Titolo Applicazione")); // cambiare titolo

    QWidget *central = new QWidget(this);
    mainLayout = new QGridLayout(central);

    addMenu();

    QGroupBox *search = addSearch();
    QGroupBox *persone = addPersoneBox();
    QGroupBox *dettagli = addDettagliBox();

    mainLayout->addWidget(search, 0, 0);
    mainLayout->addWidget(persone, 1, 0);
    mainLayout->addWidget(dettagli, 0, 1, 2, 1);
    mainLayout->setRowStretch(0,0);
    mainLayout->setRowStretch(1,1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnMinimumWidth(0, 500);
    mainLayout->setColumnMinimumWidth(1, 200);
    mainLayout->setRowMinimumHeight(1, 150);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    resize(850, 400);
}

void Vista::guida()
{
    QMessageBox::about(this, tr("NOME APPLICAZIONE"),
            tr("<p>Questa applicazione è pensata per.....</p>"));
}

void Vista::addMenu()
{
    QMenuBar* menubar = new QMenuBar();

    QMenu* fileMenu = new QMenu("File",menubar);
    QAction* nuovo = new QAction("Nuovo",fileMenu);
    QAction* elimina = new QAction("Elimina",fileMenu);
    QAction* reset = new QAction("Reset",fileMenu);
    QAction* esci = new QAction("Esci",fileMenu);
    fileMenu->addAction(nuovo);
    fileMenu->addAction(elimina);
    fileMenu->addAction(reset);
    fileMenu->addSeparator();
    fileMenu->addAction(esci);

    QMenu* helpMenu = new QMenu("Help",menubar);
    QAction* guida = new QAction("Guida",helpMenu);
    helpMenu->addAction(guida);

    //connect(nuovo,SIGNAL(triggered()),controller,SLOT(nuovaPersona()));
    //connect per elimina
    //connect(reset,SIGNAL(triggered()),controller,SLOT(reset()));
    connect(esci,SIGNAL(triggered()),this,SLOT(close()));
    connect(guida,SIGNAL(triggered()),this,SLOT(guida()));

    menubar->addMenu(fileMenu);
    menubar->addMenu(helpMenu);

    mainLayout->setMenuBar(menubar);
}

QGroupBox *Vista::addSearch()
{
    QLineEdit *searchbox = new QLineEdit();
    searchbox->setPlaceholderText("Inserisci il nome della persona che cerchi");
    searchbox->setClearButtonEnabled(true);

    QGroupBox *box = new QGroupBox(tr("Cerca"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(searchbox, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox *Vista::addPersoneBox()
{
    QGroupBox *box = new QGroupBox(tr("Persone"));



    return box;
}

QGroupBox *Vista::addDettagliBox()
{
    QGroupBox *box = new QGroupBox(tr("Dettagli"));

    return box;
}

void Vista::nuovaPersona()
{

}
