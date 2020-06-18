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
        paga = new QDoubleSpinBox();
        paga->setRange(0, 9999);
        layout->addRow("Paga Oraria:", paga);

        ore = new QSpinBox();
        layout->addRow("Ore Lavoro:", ore);

        QGroupBox * cattedra = new QGroupBox();
        cattSi = new QRadioButton(tr("&Si"));
        QRadioButton * no = new QRadioButton(tr("N&o"));
        cattSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(cattSi);
        box->addWidget(no);
        cattedra->setLayout(box);
        layout->addRow("Cattedra:", cattedra);

        QPushButton * crea = new QPushButton("Crea");
        layout->addRow(crea);

        // DA AGGIUNGERE ANCHE SUGLI ALTRI TIPI
        connect(crea,SIGNAL(clicked()),this,SLOT(creaDocente()));

        setLayout(layout);
    }
    if (t == dottorando)
    {
        corso = new QComboBox();
        corso->insertItem(0, "Ingegneria");
        corso->insertItem(1, "Informatica");
        corso->insertItem(2, "Psicologia");
        corso->insertItem(3, "Economia");
        layout->addRow("Corso:", corso);

        QGroupBox * regolare = new QGroupBox();
        regSi = new QRadioButton(tr("&Si"));
        QRadioButton * no = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(no);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        ricerca = new QLineEdit();
        layout->addRow("Ricerca:", ricerca);

        QPushButton * crea = new QPushButton("Crea");
        layout->addRow(crea);

        setLayout(layout);
    }

    if (t == laureando)
    {
        corso = new QComboBox();
        corso->insertItem(0, "Ingegneria");
        corso->insertItem(1, "Informatica");
        corso->insertItem(2, "Psicologia");
        corso->insertItem(3, "Economia");
        layout->addRow("Corso:", corso);

        QGroupBox * regolare = new QGroupBox();
        regSi = new QRadioButton(tr("&Si"));
        QRadioButton * no = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(no);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        votoBase = new QSpinBox();
        votoBase->setRange(60, 110);
        layout->addRow("Voto Base:", votoBase);

        bonusVoto = new QSpinBox();
        layout->addRow("Bonus Voto:", bonusVoto);

        QPushButton * crea = new QPushButton("Crea");
        layout->addRow(crea);

        setLayout(layout);
    }

    if (t == studlavoratore)
    {
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
        QRadioButton * no = new QRadioButton(tr("N&o"));
        regSi->setChecked(true);
        QHBoxLayout *box = new QHBoxLayout;
        box->addWidget(regSi);
        box->addWidget(no);
        regolare->setLayout(box);
        layout->addRow("Regolare:", regolare);

        media = new QDoubleSpinBox();
        media->setRange(0, 30);
        layout->addRow("Media:", media);

        QPushButton * crea = new QPushButton("Crea");
        layout->addRow(crea);

        setLayout(layout);
    }

    if (t == tecnico)
    {
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

        QPushButton * crea = new QPushButton("Crea");
        layout->addRow(crea);

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
