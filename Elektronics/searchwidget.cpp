#include "searchwidget.h"
#include <QLabel>
#include <QBoxLayout>
#include <QGridLayout>

SearchWidget::SearchWidget(QWidget* parent): QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* prezzoLayout = new QHBoxLayout();
    QLabel* ramMemLabel = new QLabel("Memoria Ram (Gb):",this);
    QLabel* prezzoLabel = new QLabel("Prezzo Minimo:",this);
    QLabel* cpuLabel = new QLabel("nome CPU:", this);
    QLabel* gpuLabel = new QLabel("Memoria Dedicata GPU:", this);
    QLabel* hddLabel = new QLabel("Memoria Hard Disk (Gb):",this);
    QLabel* schermoLabel = new QLabel("Dimensione Schermo (pollici):",this);
    sprezzo = new QSlider(Qt::Horizontal,this);
    sprezzo->setTickInterval(300);
    sprezzo->setRange(0,1800);
    sprezzo->setTickPosition(QSlider::TicksBelow);
    cpu = new QComboBox(this);
    cpu->addItem("none");
    cpu->addItem("i2");
    cpu->addItem("i3");
    cpu->addItem("i5");
    cpu->addItem("i7");
    cpu->addItem("i9");
    gpuMemory = new QComboBox(this);
    gpuMemory->addItem("none");
    gpuMemory->addItem("4");
    gpuMemory->addItem("6");
    gpuMemory->addItem("8");
    gpuMemory->addItem("16");
    hddMemory = new QComboBox(this);
    hddMemory->addItem("none");
    hddMemory->addItem("64");
    hddMemory->addItem("128");
    hddMemory->addItem("256");
    hddMemory->addItem("512");
    hddMemory->addItem("1000");
    hddMemory->addItem("2000");
    sizeSchermo = new QComboBox(this);
    sizeSchermo->addItem("none");
    sizeSchermo->addItem("3");
    sizeSchermo->addItem("4");
    sizeSchermo->addItem("5");
    sizeSchermo->addItem("6");
    ramMemory = new QComboBox(this);
    ramMemory->addItem("none");
    ramMemory->addItem("4");
    ramMemory->addItem("6");
    ramMemory->addItem("8");
    ramMemory->addItem("12");
    ramMemory->addItem("16");
    ramMemory->addItem("32");
    valueprezzo = new QLabel(QString::fromStdString(std::to_string(sprezzo->value())),this);
    prezzoLayout->addWidget(prezzoLabel);
    prezzoLayout->addWidget(valueprezzo);
    mainLayout->addLayout(prezzoLayout);
    mainLayout->addWidget(sprezzo);
    mainLayout->addWidget(cpuLabel);
    mainLayout->addWidget(cpu);
    mainLayout->addWidget(gpuLabel);
    mainLayout->addWidget(gpuMemory);
    mainLayout->addWidget(hddLabel);
    mainLayout->addWidget(hddMemory);
    mainLayout->addWidget(schermoLabel);
    mainLayout->addWidget(sizeSchermo);
    mainLayout->addWidget(ramMemLabel);
    mainLayout->addWidget(ramMemory);
    connect(ramMemory,SIGNAL(currentIndexChanged(int)),this, SIGNAL(searchChanged()));
    connect(cpu,SIGNAL(currentIndexChanged(int)),this, SIGNAL(searchChanged()));
    connect(hddMemory,SIGNAL(currentIndexChanged(int)),this, SIGNAL(searchChanged()));
    connect(sizeSchermo,SIGNAL(currentIndexChanged(int)),this, SIGNAL(searchChanged()));
    connect(gpuMemory,SIGNAL(currentIndexChanged(int)),this, SIGNAL(searchChanged()));
    connect(sprezzo, SIGNAL(valueChanged(int)),this,SLOT(setValuePrezzo()));
    connect(sprezzo, SIGNAL(valueChanged(int)), this, SIGNAL(searchChanged()));
    setFixedWidth(230);
}

std::string SearchWidget::getMemory()
{
    return ramMemory->currentText().toStdString();
}

std::string SearchWidget::getCpu()
{
    return cpu->currentText().toStdString();
}

std::string SearchWidget::getGpu()
{
    return gpuMemory->currentText().toStdString();
}

std::string SearchWidget::getHdd()
{
    return hddMemory->currentText().toStdString();
}

int SearchWidget::getSchermo()
{
    switch(sizeSchermo->currentIndex())
    {
    case 0:
        return 0;
    case 1:
        return 3;
    case 2:
        return 4;
    case 3:
        return 5;
    case 4:
        return 6;

    }
    return 0;
}

int SearchWidget::getValuePrezzo()
{
    return sprezzo->value();
}
void SearchWidget::setValuePrezzo()
{
    valueprezzo->setText(QString::fromStdString(std::to_string(sprezzo->value())));
}
