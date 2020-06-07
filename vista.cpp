#include "vista.h"
#include "controller.h"

Vista::Vista(Controller * c, QWidget *parent) : QMainWindow(parent), controller(c)
{
    setWindowTitle(tr("Titolo Applicazione")); // cambiare titolo

    QWidget * central = new QWidget(this);
    mainLayout = new QGridLayout(central);

    addMenu();

    QGroupBox * search = addSearch();
    QGroupBox * lcd = addLCD();
    QGroupBox * persone = addPersoneBox();
    QGroupBox * dettagli = addDettagliBox();

    mainLayout->addWidget(search, 0, 0);
    mainLayout->addWidget(lcd, 0, 1);
    mainLayout->addWidget(persone, 1, 0);
    mainLayout->addWidget(dettagli, 1, 1);
    mainLayout->setRowStretch(0,0);
    mainLayout->setRowStretch(1,1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnMinimumWidth(0, 350);
    mainLayout->setColumnMinimumWidth(1, 225);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    resize(700, 450);
}

void Vista::showGuida()
{
    QMessageBox::about(this, tr("NOME APPLICAZIONE"),
            tr("<p>Questa applicazione è pensata per.....</p>"));
}

void Vista::addMenu()
{
    QMenuBar * menubar = new QMenuBar();

    QMenu * fileMenu = new QMenu("File",menubar);
    QMenu * nuovo = fileMenu->addMenu("Nuovo");

    QAction * elimina = fileMenu->addAction("Elimina");
    QAction * reset = fileMenu->addAction("Reset");
    QAction * esci = fileMenu->addAction("Esci");

    QAction * docente = nuovo->addAction("Docente");
    QAction * dottorando = nuovo->addAction("Dottorando");
    QAction * laureando = nuovo->addAction("Laureando");
    QAction * studentelavoratore = nuovo->addAction("Studente Lavoratore");
    QAction * tecnico = nuovo->addAction("Tecnico");

    QMenu * helpMenu = new QMenu("Help",menubar);
    QAction * guida = new QAction("Guida",helpMenu);
    helpMenu->addAction(guida);

    //la connect per nuovo: unica o una per tipo?
    //fare le altre connect
    //connect(reset,SIGNAL(triggered()),controller,SLOT(reset()));
    connect(esci,SIGNAL(triggered()),this,SLOT(close()));
    connect(guida,SIGNAL(triggered()),this,SLOT(showGuida()));

    menubar->addMenu(fileMenu);
    menubar->addMenu(helpMenu);

    mainLayout->setMenuBar(menubar);
}

QGroupBox * Vista::addSearch()
{
    QLineEdit * searchbox = new QLineEdit();
    searchbox->setPlaceholderText("Inserisci qui il nome della persona che cerchi");
    searchbox->setClearButtonEnabled(true);

    QGroupBox * box = new QGroupBox(tr("Cerca:"));
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(searchbox, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox * Vista::addLCD()
{
    QLCDNumber * lcd = new QLCDNumber(9);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->display(-3585.85);

    QGroupBox * box = new QGroupBox(tr("Bilancio:"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lcd, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox * Vista::addPersoneBox()
{
    QGroupBox * box = new QGroupBox(tr("Persone:"));

    QButtonGroup * persone = new QButtonGroup();

    for (unsigned int i = 0; i <= controller->getSize(); i++) {
        DatiPersona dati = controller->getDatiPersona();
        QString nome = basic_string(dati.nome);
        QPushButton * bottone = new QPushButton();
        persone->addButton(bottone);
    }

    return box;
}

QGroupBox * Vista::addDettagliBox()
{
    QGroupBox *box = new QGroupBox(tr("Dettagli:"));

    return box;
}

DatiPersona::DatiPersona(tipo t, std::string n, unsigned short e, double paga, unsigned short ore, bool cat, double bonusD, corsoLau c, bool reg, double med, std::string ric, unsigned short voto, unsigned short bonusV)
{
    switch (t)
    {
        nome = n;
        eta = e;
        case docente:
            pagaOraria = paga;
            oreLavoro = ore;
            cattedra = cat;
            bonusDocente = bonusD;
        ;

        case dottorando:
            corso = c;
            regolare = reg;
            media = med;
            ricerca = ric;
        ;

        case laureando:
            corso = c;
            regolare = reg;
            media = med;
            votoBase = voto;
            bonusVoto = bonusV;
        ;

        case studentelavoratore:
            pagaOraria = paga;
            oreLavoro = ore;
            corso = c;
            regolare = reg;
            media = med;
        ;

        case tecnico:
            pagaOraria = paga;
            oreLavoro = ore;
        ;
    }
}
