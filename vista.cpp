#include "vista.h"
#include "controller.h"

Vista::Vista(Controller * c, QWidget *parent) : QMainWindow(parent), controller(c)
{
    setWindowTitle(tr("NOME APPLICAZIONE")); // cambiare titolo

    QWidget * central = new QWidget(this);
    mainLayout = new QGridLayout(central);

    addMenu();

    addSearch();
    addLCD();
    addPersoneBox();
    addDettagliBox();

    mainLayout->addWidget(search, 0, 0);
    mainLayout->addWidget(lcd, 0, 1);
    mainLayout->addWidget(persone, 1, 0);
    mainLayout->addWidget(dettagli, 1, 1);
    mainLayout->setRowStretch(0,0);
    mainLayout->setRowStretch(1,1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnMinimumWidth(0, 300);
    mainLayout->setColumnMinimumWidth(1, 300);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    setMinimumSize(400, 400);
}

void Vista::aggiornaApp()
{
    delete lcd;
    delete persone;
    delete dettagli;

    QWidget * central = new QWidget(this);
    mainLayout = new QGridLayout(central);

    addMenu();

    addLCD();
    addPersoneBox();
    addDettagliBox();

    mainLayout->addWidget(search, 0, 0);
    mainLayout->addWidget(lcd, 0, 1);
    mainLayout->addWidget(persone, 1, 0);
    mainLayout->addWidget(dettagli, 1, 1);
    mainLayout->setRowStretch(0,0);
    mainLayout->setRowStretch(1,1);
    mainLayout->setColumnStretch(1, 1);
    mainLayout->setColumnMinimumWidth(0, 300);
    mainLayout->setColumnMinimumWidth(1, 300);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void Vista::showGuida()
{
    QMessageBox::about(this, tr("NOME APPLICAZIONE"),  // cambiare titolo
                       tr("<p>Questa applicazione è pensata per.....</p>"));  // mettere guida
}

void Vista::resetApp()
{
    controller->resetVettore();

    aggiornaApp();
}

void Vista::dettagliDocente()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Docente:"));
    mainLayout->addWidget(dettagli, 1, 1);

//    QScrollArea * scrollArea = new QScrollArea();
//    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    scrollArea->setWidgetResizable(true);
//    scrollArea->setGeometry(10, 10, 100, 100);
//    QWidget *widget = new QWidget();
//    scrollArea->setWidget(widget);
//    QVBoxLayout * lista = new QVBoxLayout();
//    widget->setLayout(lista);

//    Bottone * bottone = qobject_cast<Bottone *>(sender());
//    unsigned short i = bottone->getIndice();

//    QLabel * nome = new QLabel ("Ciao");
//    lista->addWidget(nome);

//    QGridLayout * layout = new QGridLayout;
//    layout->addWidget(scrollArea, 0, 0);
//    dettagli->setLayout(layout);
}

void Vista::dettagliDottorando()
{

}

void Vista::dettagliLaureando()
{

}

void Vista::dettagliStudLav()
{

}

void Vista::dettagliTecnico()
{

}

void Vista::addDocente()
{
    Dialog * finestra = new Dialog(controller, this, docente);

    finestra->exec();
}

void Vista::addDottorando()
{
    Dialog * finestra = new Dialog(controller,  this, dottorando);

    finestra->exec();
}

void Vista::addLaureando()
{
    Dialog * finestra = new Dialog(controller,  this, laureando);

    finestra->exec();
}

void Vista::addStudLav()
{
    Dialog * finestra = new Dialog(controller,  this, studlavoratore);

    finestra->exec();
}

void Vista::addTecnico()
{
    Dialog * finestra = new Dialog(controller,  this, tecnico);

    finestra->exec();
}

void Vista::addMenu()
{
    QMenuBar * menubar = new QMenuBar();

    QMenu * fileMenu = new QMenu("File",menubar);
    QMenu * nuovo = fileMenu->addMenu("Nuovo");

    QAction * reset = fileMenu->addAction("Reset");
    QAction * esci = fileMenu->addAction("Esci");
    connect(reset,SIGNAL(triggered()),this,SLOT(resetApp()));
    connect(esci,SIGNAL(triggered()),this,SLOT(close()));

    QAction * docente = nuovo->addAction("Docente");
    QAction * dottorando = nuovo->addAction("Dottorando");
    QAction * laureando = nuovo->addAction("Laureando");
    QAction * studentelavoratore = nuovo->addAction("Studente Lavoratore");
    QAction * tecnico = nuovo->addAction("Tecnico");
    connect(docente, SIGNAL(triggered()), this, SLOT(addDocente()));
    connect(dottorando, SIGNAL(triggered()), this, SLOT(addDottorando()));
    connect(laureando, SIGNAL(triggered()), this, SLOT(addLaureando()));
    connect(studentelavoratore, SIGNAL(triggered()), this, SLOT(addStudLav()));
    connect(tecnico, SIGNAL(triggered()), this, SLOT(addTecnico()));

    QMenu * helpMenu = new QMenu("Help",menubar);
    QAction * guida = new QAction("Guida",helpMenu);
    helpMenu->addAction(guida);
    connect(guida,SIGNAL(triggered()),this,SLOT(showGuida()));

    menubar->addMenu(fileMenu);
    menubar->addMenu(helpMenu);

    mainLayout->setMenuBar(menubar);
}

void Vista::addSearch()
{
    search = new QGroupBox(tr("Cerca:"));

    QLineEdit * cerca = new QLineEdit();
    cerca->setPlaceholderText("Inserisci qui il nome della persona che cerchi");
    cerca->setClearButtonEnabled(true);

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(cerca, 0, 0);
    search->setLayout(layout);
}

void Vista::addLCD()
{
    lcd = new QGroupBox(tr("Totale:"));

    QLCDNumber * screen = new QLCDNumber(9);
    screen->setSegmentStyle(QLCDNumber::Flat);
    short int costo = controller->getCosto();
    screen->display(costo);

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(screen, 0, 0);
    lcd->setLayout(layout);
}

void Vista::addPersoneBox()
{
    persone = new QGroupBox(tr("Persone:"));

    QScrollArea * scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setWidgetResizable(true);
    scrollArea->setGeometry(10, 10, 100, 100);

    QWidget *widget = new QWidget();
    scrollArea->setWidget(widget);

    QVBoxLayout * lista = new QVBoxLayout();
    widget->setLayout(lista);

    for (unsigned short i = 0; i < controller->getSize(); i++) {
        QString nome = controller->getNomePersona(i);
        tipo t = controller->getTipoPersona(i);
        Bottone * bottone = new Bottone(i, t);
        switch (t) {
            case docente: connect(bottone,SIGNAL(clicked()),this,SLOT(dettagliDocente()));
//            case dottorando: connect(bottone,SIGNAL(clicked()),this,SLOT(dettagliDottorando()));
//            case laureando: connect(bottone,SIGNAL(clicked()),this,SLOT(dettagliLaureando()));
//            case studlavoratore: connect(bottone,SIGNAL(clicked()),this,SLOT(dettagliStudLav()));
//            case tecnico: connect(bottone,SIGNAL(clicked()),this,SLOT(dettagliTecnico()));
        }
        bottone->setText(nome);
        lista->addWidget(bottone);
    }

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(scrollArea, 0, 0);
    persone->setLayout(layout);
}

void Vista::addDettagliBox()
{
    dettagli = new QGroupBox(tr("Dettagli:"));
}
