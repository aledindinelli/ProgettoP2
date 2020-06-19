#include "dialog.h"
#include "controller.h"

Dialog::Dialog(Controller * c, Vista * v, tipo t, QWidget * parent) : QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), controller(c), vista(v)
{
    layout = new QFormLayout();

    nome = new QLineEdit("");
    layout->addRow("Nome:", nome);

    eta = new QSpinBox();
    eta->setMinimum(18);
    layout->addRow("Età:", eta);

    if (t == docente)
    {
        setWindowTitle(tr("Nuovo Docente"));

        paga = new QDoubleSpinBox();
        paga->setRange(0, 9999);
        layout->addRow("Paga Oraria:", paga);

        ore = new QSpinBox();
        layout->addRow("Ore Lavoro:", ore);

        QGroupBox * cattedra = new QGroupBox();
        cattSi = new QRadioButton(tr("&Si"));
        cattNo = new QRadioButton(tr("N&o"));
        cattSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(cattSi);
        box->addWidget(cattNo);
        cattedra->setLayout(box);
        layout->addRow("Cattedra:", cattedra);

        invio = new Bottone(-1, t);
        invio->setText("Crea");
        layout->addRow(invio);
        connect(invio,SIGNAL(clicked()),this,SLOT(creaDocente()));

        setLayout(layout);
    }

    if (t == dottorando)
    {
        setWindowTitle(tr("Nuovo Dottorando"));

        corso = new QComboBox();
        corso->insertItem(0, "Ingegneria");
        corso->insertItem(1, "Informatica");
        corso->insertItem(2, "Psicologia");
        corso->insertItem(3, "Economia");
        layout->addRow("Corso:", corso);

        QGroupBox * regolare = new QGroupBox();
        regSi = new QRadioButton(tr("&Si"));
        regNo = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(regNo);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        ricerca = new QLineEdit();
        layout->addRow("Ricerca:", ricerca);

        invio = new Bottone(-1, t);
        invio->setText("Crea");
        layout->addRow(invio);
        connect(invio,SIGNAL(clicked()),this,SLOT(creaDottorando()));

        setLayout(layout);
    }

    if (t == laureando)
    {
        setWindowTitle(tr("Nuovo Laureando"));

        corso = new QComboBox();
        corso->insertItem(0, "Ingegneria");
        corso->insertItem(1, "Informatica");
        corso->insertItem(2, "Psicologia");
        corso->insertItem(3, "Economia");
        layout->addRow("Corso:", corso);

        QGroupBox * regolare = new QGroupBox();
        regSi = new QRadioButton(tr("&Si"));
        regNo = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(regNo);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        votoBase = new QSpinBox();
        votoBase->setRange(60, 110);
        layout->addRow("Voto Base:", votoBase);

        invio = new Bottone(-1, t);
        invio->setText("Crea");
        layout->addRow(invio);
        connect(invio,SIGNAL(clicked()),this,SLOT(creaLaureando()));

        setLayout(layout);
    }

    if (t == studlavoratore)
    {
        setWindowTitle(tr("Nuovo Studente Lavoratore"));

        paga = new QDoubleSpinBox();
        paga->setRange(0, 9999);
        layout->addRow("Paga Oraria:", paga);

        ore = new QSpinBox();
        layout->addRow("Ore Lavoro:", ore);

        corso = new QComboBox();
        corso->insertItem(0, "Ingegneria");
        corso->insertItem(1, "Informatica");
        corso->insertItem(2, "Psicologia");
        corso->insertItem(3, "Economia");
        layout->addRow("Corso:", corso);

        QGroupBox * regolare = new QGroupBox();
        regSi = new QRadioButton(tr("&Si"));
        regNo = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(regNo);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        invio = new Bottone(-1, t);
        invio->setText("Crea");
        layout->addRow(invio);
        connect(invio,SIGNAL(clicked()),this,SLOT(creaStudLav()));

        setLayout(layout);
    }

    if (t == tecnico)
    {
        setWindowTitle(tr("Nuovo Tecnico"));

        paga = new QDoubleSpinBox();
        paga->setRange(0, 9999);
        layout->addRow("Paga Oraria:", paga);

        ore = new QSpinBox();
        layout->addRow("Ore Lavoro:", ore);

        reparto = new QComboBox();
        reparto->insertItem(0, "Server");
        reparto->insertItem(1, "Laboratorio");
        reparto->insertItem(2, "Ufficio");
        layout->addRow("Reparto:", reparto);

        invio = new Bottone(-1, t);
        invio->setText("Crea");
        layout->addRow(invio);
        connect(invio,SIGNAL(clicked()),this,SLOT(creaTecnico()));

        setLayout(layout);
    }
}

void Dialog::creaDocente()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();
    bool c = false; if (cattSi->isChecked()) {c=true;}

    controller->nuovoDocente(name, e, p, o, c);

    vista->aggiornaApp();
    emit close();
}

void Dialog::creaDottorando()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    std::string ric = ricerca->text().toStdString();

    int indice = corso->currentIndex();
    if (indice == 0) {
        controller->nuovoDottorando(name, e, ingegneria, regSi->isChecked(), med, ric);
    }
    if (indice == 1) {
        controller->nuovoDottorando(name, e, informatica, regSi->isChecked(), med, ric);
    }
    if (indice == 2) {
        controller->nuovoDottorando(name, e, psicologia, regSi->isChecked(), med, ric);
    }
    if (indice == 3) {
        controller->nuovoDottorando(name, e, economia, regSi->isChecked(), med, ric);
    }

    vista->aggiornaApp();
    emit close();
}

void Dialog::creaLaureando()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    unsigned short voto = votoBase->value();

    int indice = corso->currentIndex();
    if (indice == 0) {
        controller->nuovoLaureando(name, e, ingegneria, regSi->isChecked(), med, voto);
    }
    if (indice == 1) {
        controller->nuovoLaureando(name, e, informatica, regSi->isChecked(), med, voto);
    }
    if (indice == 2) {
        controller->nuovoLaureando(name, e, psicologia, regSi->isChecked(), med, voto);
    }
    if (indice == 3) {
        controller->nuovoLaureando(name, e, economia, regSi->isChecked(), med, voto);
    }

    vista->aggiornaApp();
    emit close();
}

void Dialog::creaStudLav()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    double p = paga->value();
    unsigned short o = ore->value();

    int indice = corso->currentIndex();
    if (indice == 0) {
        controller->nuovoStudLav(name, e, ingegneria, regSi->isChecked(), med, o, p);
    }
    if (indice == 1) {
        controller->nuovoStudLav(name, e, informatica, regSi->isChecked(), med, o, p);
    }
    if (indice == 2) {
        controller->nuovoStudLav(name, e, psicologia, regSi->isChecked(), med, o, p);
    }
    if (indice == 3) {
        controller->nuovoStudLav(name, e, economia, regSi->isChecked(), med, o, p);
    }

    vista->aggiornaApp();
    emit close();
}

void Dialog::creaTecnico()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();

    int indice = reparto->currentIndex();
    if (indice == 0) {
        controller->nuovoTecnico(name, e, p, o, server);
    }
    if (indice == 1) {
        controller->nuovoTecnico(name, e, p, o, laboratorio);
    }
    if (indice == 2) {
        controller->nuovoTecnico(name, e, p, o, ufficio);
    }

    vista->aggiornaApp();
    emit close();
}
