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
    mainLayout->setColumnMinimumWidth(0, 350);
    mainLayout->setColumnMinimumWidth(1, 200);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    resize(700, 400);
}

void Vista::aggiornaApp()
{
    delete lcd;
    delete persone;
    delete dettagli;
    delete mainLayout;

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
    mainLayout->setColumnMinimumWidth(0, 350);
    mainLayout->setColumnMinimumWidth(1, 200);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
}

void Vista::showGuida()
{
    QMessageBox::about(this, tr("NOME APPLICAZIONE"),  // cambiare titolo
                       tr("<p>"
                          "Questa applicazione è pensata per boh"
                          "</p>"));  // mettere guida
}

void Vista::resetApp()
{
    controller->resetVettore();

    aggiornaApp();
}

void Vista::eliminaPersona()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    unsigned short i = bottone->getIndice();

    controller->cancellaPersona(i);

    aggiornaApp();
}

void Vista::upgradePersona()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    unsigned short i = bottone->getIndice();

    controller->upgradePersona(i);

    aggiornaApp();
}

void Vista::dettagliDocente()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Docente:"));
    mainLayout->addWidget(dettagli, 1, 1);

    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QVBoxLayout * lista = new QVBoxLayout();

    dettagliPersona(i, lista);
    dettagliImpiegato(i, lista);

    QString * Cattedra = new QString("<b>Di Ruolo:</b>  ");
    QLabel * labelCatt = new QLabel();
    if (controller->getCattedraDocente(i)) {
        Cattedra->append("Si");
    }
    else {
        Cattedra->append("No");
    }
    labelCatt->setText(*Cattedra);
    lista->addWidget(labelCatt);

    costoPersona(i, lista);

    dettagli->setLayout(lista);
}

void Vista::dettagliDottorando()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Dottorando:"));
    mainLayout->addWidget(dettagli, 1, 1);

    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QVBoxLayout * lista = new QVBoxLayout();

    dettagliPersona(i, lista);
    dettagliStudente(i, lista);

    QString * Ricerca = new QString("<b>Ricerca:</b>  ");
    Ricerca->append(controller->getRicercaDottorando(i));
    QLabel * labelRicerca = new QLabel();
    labelRicerca->setText(*Ricerca);
    lista->addWidget(labelRicerca);

    costoPersona(i, lista);

    dettagli->setLayout(lista);
}

void Vista::dettagliLaureando()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Laureando:"));
    mainLayout->addWidget(dettagli, 1, 1);

    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QVBoxLayout * lista = new QVBoxLayout();

    dettagliPersona(i, lista);
    dettagliStudente(i, lista);

    QString * Voto = new QString("<b>Base Laurea:</b>  ");
    Voto->append(QString::number(controller->getMediaStudente(i)));
    QLabel * labelVoto = new QLabel();
    labelVoto->setText(*Voto);
    lista->addWidget(labelVoto);

    costoPersona(i, lista);

    dettagli->setLayout(lista);
}

void Vista::dettagliStudLav()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Studente Lavoratore:"));
    mainLayout->addWidget(dettagli, 1, 1);

    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QVBoxLayout * lista = new QVBoxLayout();

    dettagliPersona(i, lista);
    dettagliImpiegato(i, lista);
    dettagliStudente(i, lista);

    costoPersona(i, lista);

    dettagli->setLayout(lista);
}

void Vista::dettagliTecnico()
{
    delete dettagli;
    dettagli = new QGroupBox(tr("Dettagli Tecnico:"));
    mainLayout->addWidget(dettagli, 1, 1);

    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QVBoxLayout * lista = new QVBoxLayout();

    dettagliPersona(i, lista);
    dettagliImpiegato(i, lista);

    QString * Reparto = new QString("<b>Reparto:</b>  ");
    Reparto->append(controller->getRepartoTecnico(i));
    QLabel * labelRep = new QLabel();
    labelRep->setText(*Reparto);
    lista->addWidget(labelRep);

    costoPersona(i, lista);

    dettagli->setLayout(lista);
}

void Vista::addDocente()
{
    Dialog * finestra = new Dialog(controller, this, docente, -1);

    finestra->exec();
}

void Vista::addDottorando()
{
    Dialog * finestra = new Dialog(controller,  this, dottorando, -1);

    finestra->exec();
}

void Vista::addLaureando()
{
    Dialog * finestra = new Dialog(controller,  this, laureando, -1);

    finestra->exec();
}

void Vista::addStudLav()
{
    Dialog * finestra = new Dialog(controller,  this, studlavoratore, -1);

    finestra->exec();
}

void Vista::addTecnico()
{
    Dialog * finestra = new Dialog(controller,  this, tecnico, -1);

    finestra->exec();
}

void Vista::modificaDocente()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    Dialog * finestra = new Dialog(controller, this, docente, i);
    finestra->setWindowTitle(tr("Modifica Docente"));

    QString name = controller->getNomePersona(i);
    unsigned short e = controller->getEtaPersona(i);
    unsigned short p = controller->getOreImpiegato(i);
    double o = controller->getPagaImpiegato(i);
    bool c = controller->getCattedraDocente(i);

    finestra->nome->setText(name);
    finestra->eta->setValue(e);
    finestra->paga->setValue(p);
    finestra->ore->setValue(o);
    if (!c) {
        finestra->cattSi->setChecked(false);
        finestra->cattNo->setChecked(true);
    }
    else {
        finestra->cattSi->setChecked(true);
        finestra->cattNo->setChecked(false);
    }

    finestra->exec();
}

void Vista::modificaDottorando()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    Dialog * finestra = new Dialog(controller, this, dottorando, i);
    finestra->setWindowTitle(tr("Modifica Dottorando"));

    QString name = controller->getNomePersona(i);
    unsigned short e = controller->getEtaPersona(i);
    double med = controller->getMediaStudente(i);
    bool reg = controller->getRegolareStudente(i);
    QString c = controller->getCorsoStudente(i);
    QString r = controller->getRicercaDottorando(i);

    finestra->nome->setText(name);
    finestra->eta->setValue(e);
    finestra->media->setValue(med);
    if (!reg) {
        finestra->regSi->setChecked(false);
        finestra->regNo->setChecked(true);
    }
    else {
        finestra->regSi->setChecked(true);
        finestra->regNo->setChecked(false);
    }
    if (c == "Ingegneria") {
        finestra->corso->setCurrentIndex(0);
    }
    else if (c == "Informatica") {
        finestra->corso->setCurrentIndex(1);
    }
    else if (c == "Psicologia") {
        finestra->corso->setCurrentIndex(2);
    }
    else if (c == "Economia") {
        finestra->corso->setCurrentIndex(3);
    }
    finestra->ricerca->setText(r);

    finestra->exec();
}

void Vista::modificaLaureando()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    Dialog * finestra = new Dialog(controller, this, laureando, i);
    finestra->setWindowTitle(tr("Modifica Laureando"));
    bool reg = controller->getRegolareStudente(i);
    QString name = controller->getNomePersona(i);
    unsigned short e = controller->getEtaPersona(i);
    double med = controller->getMediaStudente(i);

    QString c = controller->getCorsoStudente(i);
    unsigned short voto = controller->getVotoLaureando(i);

    finestra->nome->setText(name);
    finestra->eta->setValue(e);
    finestra->media->setValue(med);
    if (!reg) {
        finestra->regSi->setChecked(false);
        finestra->regNo->setChecked(true);
    }
    else {
        finestra->regSi->setChecked(true);
        finestra->regNo->setChecked(false);
    }
    if (c == "Ingegneria") {
        finestra->corso->setCurrentIndex(0);
    }
    else if (c == "Informatica") {
        finestra->corso->setCurrentIndex(1);
    }
    else if (c == "Psicologia") {
        finestra->corso->setCurrentIndex(2);
    }
    else if (c == "Economia") {
        finestra->corso->setCurrentIndex(3);
    }
    finestra->votoBase->setValue(voto);

    finestra->exec();
}

void Vista::modificaStudLav()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    Dialog * finestra = new Dialog(controller, this, studlavoratore, i);
    finestra->setWindowTitle(tr("Modifica Studente Lavoratore"));

    QString name = controller->getNomePersona(i);
    unsigned short e = controller->getEtaPersona(i);
    unsigned short p = controller->getOreImpiegato(i);
    double o = controller->getPagaImpiegato(i);
    double med = controller->getMediaStudente(i);
    bool reg = controller->getRegolareStudente(i);
    QString c = controller->getCorsoStudente(i);

    finestra->nome->setText(name);
    finestra->eta->setValue(e);
    finestra->paga->setValue(p);
    finestra->ore->setValue(o);
    finestra->media->setValue(med);
    if (!reg) {
        finestra->regSi->setChecked(false);
        finestra->regNo->setChecked(true);
    }
    else {
        finestra->regSi->setChecked(true);
        finestra->regNo->setChecked(false);
    }
    if (c == "Ingegneria") {
        finestra->corso->setCurrentIndex(0);
    }
    else if (c == "Informatica") {
        finestra->corso->setCurrentIndex(1);
    }
    else if (c == "Psicologia") {
        finestra->corso->setCurrentIndex(2);
    }
    else if (c == "Economia") {
        finestra->corso->setCurrentIndex(3);
    }
    finestra->exec();
}

void Vista::modificaTecnico()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    Dialog * finestra = new Dialog(controller, this, tecnico, i);
    finestra->setWindowTitle(tr("Modifica Tecnico"));

    QString name = controller->getNomePersona(i);
    unsigned short e = controller->getEtaPersona(i);
    unsigned short p = controller->getOreImpiegato(i);
    double o = controller->getPagaImpiegato(i);
    QString rep = controller->getRepartoTecnico(i);

    finestra->nome->setText(name);
    finestra->eta->setValue(e);
    finestra->paga->setValue(p);
    finestra->ore->setValue(o);
    if (rep == "Server") {
        finestra->reparto->setCurrentIndex(0);
    }
    else if (rep == "Laboratorio") {
        finestra->reparto->setCurrentIndex(1);
    }
    else if (rep == "Ufficio") {
        finestra->reparto->setCurrentIndex(2);
    }

    finestra->exec();
}

void Vista::addMenu()
{
    QMenuBar * menubar = new QMenuBar();

    QMenu * fileMenu = new QMenu("File",menubar);
    QMenu * nuovo = fileMenu->addMenu("Nuovo");

    QAction * reset = fileMenu->addAction("Reset");
    QAction * esci = fileMenu->addAction("Esci");
    connect(reset, SIGNAL(triggered()), this, SLOT(resetApp()));
    connect(esci, SIGNAL(triggered()), this, SLOT(close()));

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
    connect(guida, SIGNAL(triggered()), this, SLOT(showGuida()));

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
    double costo = controller->getCosto();
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
        QWidget * temp = new QWidget();
        QHBoxLayout * riga = new QHBoxLayout();
        riga->setContentsMargins(0, 0, 0, 0);
        riga->setSpacing(0);
        QString nome = controller->getNomePersona(i);
        tipo t = controller->getTipoPersona(i);

        Bottone * bottone = new Bottone(i, t);
        Bottone * modifica = new Bottone(i, t);
        modifica->setIcon(QIcon(":./Risorse/modify.png"));
        Bottone * upgrade = new Bottone(i, t);
//        upgrade->setIcon(QIcon(""));
        Bottone * elimina = new Bottone(i, t);
        elimina->setIcon(QIcon(":./Risorse/eraser.png"));
        riga->addWidget(bottone, 65);
        riga->addWidget(modifica, 10);
        riga->addWidget(upgrade, 10);
        riga->addWidget(elimina, 10);
        temp->setLayout(riga);

        if (t == docente) {
            connect(bottone, SIGNAL(clicked()), this, SLOT(dettagliDocente()));
            connect(modifica, SIGNAL(clicked()), this, SLOT(modificaDocente()));
        }
        if (t == dottorando) {
            connect(bottone, SIGNAL(clicked()), this, SLOT(dettagliDottorando()));
            connect(modifica, SIGNAL(clicked()), this, SLOT(modificaDottorando()));
        }
        if (t == laureando) {
            connect(bottone, SIGNAL(clicked()), this, SLOT(dettagliLaureando()));
            connect(modifica, SIGNAL(clicked()), this, SLOT(modificaLaureando()));
        }
        if (t == studlavoratore) {
            connect(bottone, SIGNAL(clicked()), this, SLOT(dettagliStudLav()));
            connect(modifica, SIGNAL(clicked()), this, SLOT(modificaStudLav()));
        }
        if (t == tecnico) {
            connect(bottone, SIGNAL(clicked()), this, SLOT(dettagliTecnico()));
            connect(modifica, SIGNAL(clicked()), this, SLOT(modificaTecnico()));
        }

        connect(upgrade, SIGNAL(clicked()), this, SLOT(upgradePersona()));
        connect(elimina, SIGNAL(clicked()), this, SLOT(eliminaPersona()));

        bottone->setText(nome);
        lista->addWidget(temp);
    }

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(scrollArea, 0, 0);
    persone->setLayout(layout);
}

void Vista::addDettagliBox()
{
    dettagli = new QGroupBox(tr("Dettagli:"));
}

void Vista::dettagliPersona(short int i, QVBoxLayout * lista)
{
    QString * Nome = new QString("<b>Nome:</b>  ");
    Nome->append(controller->getNomePersona(i));
    QLabel * labelNome = new QLabel();
    labelNome->setText(*Nome);
    lista->addWidget(labelNome);

    QString * Eta = new QString("<b>Eta:</b>  ");
    Eta->append(QString::number(controller->getEtaPersona(i)));
    QLabel * labelEta = new QLabel();
    labelEta->setText(*Eta);
    lista->addWidget(labelEta);
}

void Vista::dettagliImpiegato(short int i, QVBoxLayout * lista)
{
    QString * Paga = new QString("<b>Paga Oraria:</b>  ");
    Paga->append(QString::number(controller->getPagaImpiegato(i)));
    QLabel * labelPaga = new QLabel();
    labelPaga->setText(*Paga);
    lista->addWidget(labelPaga);

    QString * Ore = new QString("<b>Ore Lavoro:</b>  ");
    Ore->append(QString::number(controller->getOreImpiegato(i)));
    QLabel * labelOre = new QLabel();
    labelOre->setText(*Ore);
    lista->addWidget(labelOre);
}

void Vista::dettagliStudente(short int i, QVBoxLayout * lista)
{
    QString * Corso = new QString("<b>Corso:</b>  ");
    Corso->append(controller->getCorsoStudente(i));
    QLabel * labelCorso = new QLabel();
    labelCorso->setText(*Corso);
    lista->addWidget(labelCorso);

    QString * Regolare = new QString("<b>Fuori Corso:</b>  ");
    QLabel * labelReg = new QLabel();
    if (controller->getRegolareStudente(i)) {
        Regolare->append("No");
    }
    else {
        Regolare->append("Si");
    }
    labelReg->setText(*Regolare);
    lista->addWidget(labelReg);

    QString * Media = new QString("<b>Media Voti:</b>  ");
    Media->append(QString::number(controller->getMediaStudente(i)));
    QLabel * labelMedia = new QLabel();
    labelMedia->setText(*Media);
    lista->addWidget(labelMedia);
}

void Vista::costoPersona(short int i, QVBoxLayout * lista)
{
    QString * Costo = new QString("<b>Costo Persona:</b>  ");
    Costo->append(QString::number(controller->getCostoPersona(i)));
    QLabel * labelCosto = new QLabel();
    labelCosto->setText(*Costo);
    lista->addWidget(labelCosto);
}
