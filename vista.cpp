#include "vista.h"
#include "controller.h"

Vista::Vista(Controller * c, QWidget *parent) : QMainWindow(parent), controller(c)
{
    setWindowTitle(tr("NOME APPLICAZIONE")); // cambiare titolo

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
    mainLayout->setColumnMinimumWidth(0, 300);
    mainLayout->setColumnMinimumWidth(1, 300);
    mainLayout->setRowMinimumHeight(0, 70);
    mainLayout->setRowMinimumHeight(1, 200);

    central->setLayout(mainLayout);
    setCentralWidget(central);
    setMinimumSize(400, 400);
}

void Vista::showGuida()
{
    QMessageBox::about(this, tr("NOME APPLICAZIONE"),  // cambiare titolo
                       tr("<p>Questa applicazione è pensata per.....</p>"));  // mettere guida
}

void Vista::addDocente()
{
    QDialog * finestra = new QDialog();
    QFormLayout * layout = new QFormLayout();

    QLineEdit * nome = new QLineEdit();
    layout->addRow("Nome:", nome);

    QSpinBox * eta = new QSpinBox();
    layout->addRow("Età:", eta);

    QDoubleSpinBox * paga = new QDoubleSpinBox();
    paga->setRange(0, 9999);
    layout->addRow("Paga Oraria:", paga);

    QSpinBox * ore = new QSpinBox();
    layout->addRow("Ore Lavoro:", ore);

    QGroupBox * cattedra = new QGroupBox();
    QRadioButton * si = new QRadioButton(tr("&Si"));
    QRadioButton * no = new QRadioButton(tr("N&o"));
    si->setChecked(true);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(si);
    box->addWidget(no);
    cattedra->setLayout(box);
    layout->addRow("Cattedra:", cattedra);

    QHBoxLayout * hbox = new QHBoxLayout();
    QPushButton * annulla = new QPushButton("Annulla");
    QPushButton * crea = new QPushButton("Crea");
    hbox->addWidget(annulla);
    hbox->addWidget(crea);
    layout->addItem(hbox);

    connect(annulla,SIGNAL(clicked()),this,SLOT(close())); //correggere close()

    QString n = nome->text();
    unsigned int e = eta->value();
    double p = paga->value();
    unsigned int o = ore->value();
    bool c = false; if (si->isChecked()) {c=true;}

    connect(crea,SIGNAL(clicked()),this,SLOT(creaDocente(n, e, p, o, c)));

    finestra->setLayout(layout);
    finestra->exec();
}

void Vista::addDottorando()
{
    QDialog * finestra = new QDialog();
    QFormLayout * layout = new QFormLayout();

    QLineEdit * nome = new QLineEdit();
    layout->addRow("Nome:", nome);

    QSpinBox * eta = new QSpinBox();
    layout->addRow("Età:", eta);

    QComboBox * corso = new QComboBox();
    corso->insertItem(0, "Ingegneria");
    corso->insertItem(1, "Informatica");
    corso->insertItem(2, "Psicologia");
    corso->insertItem(3, "Economia");
    layout->addRow("Corso:", corso);

    QGroupBox * regolare = new QGroupBox();
    QRadioButton * si = new QRadioButton(tr("&Si"));
    QRadioButton * no = new QRadioButton(tr("N&o"));
    si->setChecked(true);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(si);
    box->addWidget(no);
    regolare->setLayout(box);
    layout->addRow("Regolare:", regolare);

    QDoubleSpinBox * media = new QDoubleSpinBox();
    media->setRange(0, 30);
    layout->addRow("Media:", media);

    QLineEdit * ricerca = new QLineEdit();
    layout->addRow("Ricerca:", ricerca);

    finestra->setLayout(layout);
    finestra->exec();
}

void Vista::addLaureando()
{
    QDialog * finestra = new QDialog();
    QFormLayout * layout = new QFormLayout();

    QLineEdit * nome = new QLineEdit();
    layout->addRow("Nome:", nome);

    QSpinBox * eta = new QSpinBox();
    layout->addRow("Età:", eta);

    QComboBox * corso = new QComboBox();
    corso->insertItem(0, "Ingegneria");
    corso->insertItem(1, "Informatica");
    corso->insertItem(2, "Psicologia");
    corso->insertItem(3, "Economia");
    layout->addRow("Corso:", corso);

    QGroupBox * regolare = new QGroupBox();
    QRadioButton * si = new QRadioButton(tr("&Si"));
    QRadioButton * no = new QRadioButton(tr("N&o"));
    si->setChecked(true);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(si);
    box->addWidget(no);
    regolare->setLayout(box);
    layout->addRow("Regolare:", regolare);

    QDoubleSpinBox * media = new QDoubleSpinBox();
    media->setRange(0, 30);
    layout->addRow("Media:", media);

    QSpinBox * votoBase = new QSpinBox();
    votoBase->setRange(60, 110);
    layout->addRow("Voto Base:", votoBase);

    QSpinBox * bonusVoto = new QSpinBox();
    layout->addRow("Bonus Voto:", bonusVoto);

    finestra->setLayout(layout);
    finestra->exec();
}

void Vista::addStudLav()
{
    QDialog * finestra = new QDialog();
    QFormLayout * layout = new QFormLayout();

    QLineEdit * nome = new QLineEdit();
    layout->addRow("Nome:", nome);

    QSpinBox * eta = new QSpinBox();
    layout->addRow("Età:", eta);

    QDoubleSpinBox * paga = new QDoubleSpinBox();
    paga->setRange(0, 9999);
    layout->addRow("Paga Oraria:", paga);

    QSpinBox * ore = new QSpinBox();
    layout->addRow("Ore Lavoro:", ore);

    QComboBox * corso = new QComboBox();
    corso->insertItem(0, "Ingegneria");
    corso->insertItem(1, "Informatica");
    corso->insertItem(2, "Psicologia");
    corso->insertItem(3, "Economia");
    layout->addRow("Corso:", corso);

    QGroupBox * regolare = new QGroupBox();
    QRadioButton * si = new QRadioButton(tr("&Si"));
    QRadioButton * no = new QRadioButton(tr("N&o"));
    si->setChecked(true);
    QHBoxLayout *box = new QHBoxLayout;
    box->addWidget(si);
    box->addWidget(no);
    regolare->setLayout(box);
    layout->addRow("Regolare:", regolare);

    QDoubleSpinBox * media = new QDoubleSpinBox();
    media->setRange(0, 30);
    layout->addRow("Media:", media);

    finestra->setLayout(layout);
    finestra->exec();
}

void Vista::addTecnico()
{
    QDialog * finestra = new QDialog();
    QFormLayout * layout = new QFormLayout();

    QLineEdit * nome = new QLineEdit();
    layout->addRow("Nome:", nome);

    QSpinBox * eta = new QSpinBox();
    layout->addRow("Età:", eta);

    QDoubleSpinBox * paga = new QDoubleSpinBox();
    paga->setRange(0, 9999);
    layout->addRow("Paga Oraria:", paga);

    QSpinBox * ore = new QSpinBox();
    layout->addRow("Ore Lavoro:", ore);

    QComboBox * reparto = new QComboBox();
    reparto->insertItem(0, "Server");
    reparto->insertItem(1, "Laboratorio");
    reparto->insertItem(2, "Ufficio");
    layout->addRow("Reparto:", reparto);

    finestra->setLayout(layout);
    finestra->exec();
}

void Vista::creaDocente(QString n, unsigned int e, double p, unsigned int o, bool c)
{
    std::string nome = n.toStdString();
    controller->nuovoDocente(nome, e, p, o, c);
}

void Vista::addMenu()
{
    QMenuBar * menubar = new QMenuBar();

    QMenu * fileMenu = new QMenu("File",menubar);
    QMenu * nuovo = fileMenu->addMenu("Nuovo");

    QAction * reset = fileMenu->addAction("Reset");
    QAction * esci = fileMenu->addAction("Esci");
    //connect reset
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
    lcd->display(0000.00);

    QGroupBox * box = new QGroupBox(tr("Totale:"));
    QGridLayout * layout = new QGridLayout;
    layout->addWidget(lcd, 0, 0);
    box->setLayout(layout);

    return box;
}

QGroupBox * Vista::addPersoneBox()
{
    QGroupBox * box = new QGroupBox(tr("Persone:"));

    QScrollArea * scrollArea = new QScrollArea(box);
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );
    scrollArea->setWidgetResizable(true);
    scrollArea->setGeometry(10, 10, 100, 100);

    QWidget *widget = new QWidget();
    scrollArea->setWidget(widget);

    QVBoxLayout * lista = new QVBoxLayout();
    widget->setLayout(lista);

    for (unsigned int i = 0; i < controller->getSize(); i++) {
        QString nome = controller->getNomePersona(i);
        QPushButton * bottone = new QPushButton(nome);
        lista->addWidget(bottone);
    }

    QGridLayout * layout = new QGridLayout;
    layout->addWidget(scrollArea);
    box->setLayout(layout);

    return box;
}

QGroupBox * Vista::addDettagliBox()
{
    QGroupBox *box = new QGroupBox(tr("Dettagli:"));

    return box;
}
