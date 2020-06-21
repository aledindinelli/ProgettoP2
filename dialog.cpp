#include "dialog.h"
#include "controller.h"

Dialog::Dialog(Controller * c, Vista * v, tipo t, short int i, QWidget * parent) : QDialog(parent, Qt::WindowTitleHint | Qt::WindowCloseButtonHint), controller(c), vista(v), indicePersona(i)
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

        if (indicePersona == -1) {
            invio = new Bottone(-1, t);
            invio->setText("Crea");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(creaDocente()));
        }
        else {
            invio = new Bottone(indicePersona, t);
            invio->setText("Modifica");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(modificaDocente()));
        }

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
        media->setRange(18, 30);
        layout->addRow("Media:", media);

        ricerca = new QLineEdit();
        layout->addRow("Ricerca:", ricerca);

        if (indicePersona == -1) {
            invio = new Bottone(-1, t);
            invio->setText("Crea");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(creaDottorando()));
        }
        else {
            invio = new Bottone(indicePersona, t);
            invio->setText("Modifica");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(modificaDottorando()));
        }

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
        media->setRange(18, 30);
        layout->addRow("Media:", media);

        votoBase = new QSpinBox();
        votoBase->setRange(60, 110);
        layout->addRow("Voto Base:", votoBase);

        if (indicePersona == -1) {
            invio = new Bottone(-1, t);
            invio->setText("Crea");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(creaLaureando()));
        }
        else {
            invio = new Bottone(indicePersona, t);
            invio->setText("Modifica");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(modificaLaureando()));
        }

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
        media->setRange(18, 30);
        layout->addRow("Media:", media);

        if (indicePersona == -1) {
            invio = new Bottone(-1, t);
            invio->setText("Crea");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(creaStudLav()));
        }
        else {
            invio = new Bottone(indicePersona, t);
            invio->setText("Modifica");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(modificaStudLav()));
        }

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

        if (indicePersona == -1) {
            invio = new Bottone(-1, t);
            invio->setText("Crea");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(creaTecnico()));
        }
        else {
            invio = new Bottone(indicePersona, t);
            invio->setText("Modifica");
            layout->addRow(invio);
            connect(invio, SIGNAL(clicked()), this, SLOT(modificaTecnico()));
        }

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

    try {
        controller->nuovoDocente(name, e, p, o, c);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::creaDottorando()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    std::string ric = ricerca->text().toStdString();
    unsigned int indice = corso->currentIndex();

    try {
        controller->nuovoDottorando(name, e, indice, regSi->isChecked(), med, ric);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::creaLaureando()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    unsigned short voto = votoBase->value();
    unsigned int indice = corso->currentIndex();

    try {
        controller->nuovoLaureando(name, e, indice, regSi->isChecked(), med, voto);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::creaStudLav()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double med = media->value();
    double p = paga->value();
    unsigned short o = ore->value();
    unsigned int indice = corso->currentIndex();

    try {
        controller->nuovoStudLav(name, e, indice, regSi->isChecked(), med, o, p);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::creaTecnico()
{
    std::string name = nome->text().toStdString();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();
    unsigned int r = reparto->currentIndex();

    try {
        controller->nuovoTecnico(name, e, p, o, r);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::modificaDocente()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QString name = nome->text();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();
    bool c = false; if (cattSi->isChecked()) {c=true;};

    try {
        controller->modificaDocente(name, e, p, o, c, i);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::modificaDottorando()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QString name = nome->text();
    unsigned short e = eta->value();
    bool reg = regSi->isChecked();
    double med = media->value();
    int indice = corso->currentIndex();
    QString ric = ricerca->text();

    try {
        controller->modificaDottorando(name, e, indice, reg, med, ric, i);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::modificaLaureando()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QString name = nome->text();
    unsigned short e = eta->value();
    bool reg = regSi->isChecked();
    double med = media->value();
    int indice = corso->currentIndex();
    unsigned short voto = votoBase->value();

    try {
        controller->modificaLaureando(name, e, indice, reg, med, voto, i);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::modificaStudLav()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QString name = nome->text();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();
    bool reg = regSi->isChecked();
    double med = media->value();
    int indice = corso->currentIndex();

    try {
        controller->modificaStudLav(name, e, p, o, indice, reg, med, i);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}

void Dialog::modificaTecnico()
{
    Bottone* bottone = qobject_cast<Bottone *>(sender());
    short int i = bottone->getIndice();

    QString name = nome->text();
    unsigned short e = eta->value();
    double p = paga->value();
    unsigned short o = ore->value();
    int r = reparto->currentIndex();

    try {
        controller->modificaTecnico(name, e, p, o, r, i);
        vista->aggiornaApp();
        emit close();
    } catch (std::exception* exc) {
        vista->showErrorMessage(exc->what());
    }
}
