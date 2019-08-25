#include "additemwidget.h"
#include "items.h"

#include <QComboBox>
#include <QBoxLayout>
#include <QLabel>

AddItemWidget::AddItemWidget(QWidget* parent): QWidget(parent), type(new QComboBox(this)), nomeRam(new QLineEdit(this)), gbRam(new QLineEdit(this)), typeRam(new QLineEdit(this)), nomeCPU(new QLineEdit(this)), clockCPU(new QLineEdit(this)), graphicCPU(new QLineEdit(this)), nomeCool(new QLineEdit(this)), typeCool(new QLineEdit(this)), nomeGPU(new QLineEdit(this)), memorygpu(new QLineEdit(this)), clockgpu(new QLineEdit(this)), nomehdd(new QLineEdit(this)), gbhdd(new QLineEdit(this)), typehdd(new QLineEdit(this)), mahbat(new QLineEdit(this)), hours_bat(new QLineEdit(this)), num_fotocamera(new QLineEdit(this)), sensorefotocamera(new QCheckBox(this)), flashfotocamera(new QCheckBox(this)), num_secfotocamera(new QLineEdit(this)), sensoresecfotocamera(new QCheckBox(this)), flashsecfotocamera(new QCheckBox(this)), retroilltast(new QCheckBox(this)), typetastiera(new QLineEdit(this)), resolutionschermo(new QLineEdit(this)), sizeschermo(new QLineEdit(this)), tecSchermo(new QLineEdit(this)), nomeComputer(new QLineEdit(this)), prezzoComputer(new QLineEdit(this)), coloreComputer(new QLineEdit(this)), marcaComputer(new QLineEdit(this)), touchTablet(new QCheckBox(this)), multitouchTablet(new QCheckBox(this)), pennaTablet(new QCheckBox(this)), weightPC(new QLineEdit(this)), tastieraTwoInOne(new QCheckBox(this)), wifiPhone(new QCheckBox(this)), gpsPhone(new QCheckBox(this)), touchPhone(new QCheckBox(this)), g3Phone(new QCheckBox(this)), simPhone(new QLineEdit(this)), g4Smart(new QCheckBox(this)), sdSmart(new QCheckBox(this)), sensoreSmart(new QCheckBox(this)), multitouchSmart(new QCheckBox(this)), pesoSmart(new QLineEdit(this)), scoccaSmart(new QLineEdit(this)), osSmart(new QLineEdit(this))
{
    type->addItem("Computer");
    type->addItem("Tablet");
    type->addItem("PC");
    type->addItem("TwoInOne");
    type->addItem("SmartPhone");

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* ramLayout = new QHBoxLayout();
    QHBoxLayout* cpuLayout = new QHBoxLayout();
    QHBoxLayout* gpuLayout = new QHBoxLayout();
    QHBoxLayout* coolLayout = new QHBoxLayout();
    QHBoxLayout* hdLayout = new QHBoxLayout();
    QHBoxLayout* batLayout = new QHBoxLayout();
    QHBoxLayout* cameraLayout = new QHBoxLayout();
    QHBoxLayout* camerasecLayout = new QHBoxLayout();
    QHBoxLayout* schermoLayout = new QHBoxLayout();
    QHBoxLayout* ComputerLayout = new QHBoxLayout();
    QHBoxLayout* tastieraLayout = new QHBoxLayout();
    QHBoxLayout* TabletLayout = new QHBoxLayout();
    QHBoxLayout* PCLayout = new QHBoxLayout();
    QHBoxLayout* TwoInOneLayout = new QHBoxLayout();
    QHBoxLayout* PhoneLayout = new QHBoxLayout();
    QHBoxLayout* Smart1Layout = new QHBoxLayout();
    QHBoxLayout* Smart2Layout = new QHBoxLayout();
    batContainer = new QWidget(this);
    cameraContainer = new QWidget(this);
    camerasecContainer = new QWidget(this);
    schermoContainer = new QWidget(this);
    tastContainer = new QWidget(this);
    computerContainer = new QWidget(this);
    tabletContainer = new QWidget(this);
    pcContainer = new QWidget(this);
    twoinoneContainer = new QWidget(this);
    phoneContainer = new QWidget(this);
    smartphone1Container = new QWidget(this);
    smartphone2Container = new QWidget(this);
    batContainer->setLayout(batLayout);
    cameraContainer->setLayout(cameraLayout);
    camerasecContainer->setLayout(camerasecLayout);
    schermoContainer->setLayout(schermoLayout);
    tastContainer->setLayout(tastieraLayout);
    computerContainer->setLayout(ComputerLayout);
    tabletContainer->setLayout(TabletLayout);
    pcContainer->setLayout(PCLayout);
    twoinoneContainer->setLayout(TwoInOneLayout);
    phoneContainer->setLayout(PhoneLayout);
    smartphone1Container->setLayout(Smart1Layout);
    smartphone2Container->setLayout(Smart2Layout);




    QLabel* ramLabel = new QLabel("Ram",this);
    QLabel* ramgbLabel = new QLabel("GBytes:",this);
    QLabel* ramtypeLabel = new QLabel("Tipo:",this);
    QLabel* ramnomeLabel = new QLabel("Nome:",this);
    QLabel* cpuLabel = new QLabel("CPU",this);
    QLabel* cpuclockLabel = new QLabel("Clock speed:",this);
    QLabel* cpugraphicLabel = new QLabel("Scheda grafica:",this);
    QLabel* cpunomeLabel = new QLabel("Nome:",this);
    QLabel* coolLabel = new QLabel("Sistema di Raffreddamento",this);
    QLabel* coolnomeLabel = new QLabel("Nome:",this);
    QLabel* cooltypeLabel = new QLabel("Tipo:",this);
    QLabel* GPULabel = new QLabel("Scheda Grafica",this);
    QLabel* gpunomeLabel = new QLabel("Nome:",this);
    QLabel* gpugbLabel = new QLabel("GBytes:",this);
    QLabel* gpuclockLabel = new QLabel("Clock speed",this);
    QLabel* HDDLabel = new QLabel("Memoria",this);
    QLabel* hddnomeLabel = new QLabel("Nome:",this);
    QLabel* hddgbLabel = new QLabel("Memoria:",this);
    QLabel* hddtypeLabel = new QLabel("Tipo:",this);
    batLabel = new QLabel("Batteria",this);
    QLabel* mahbatLabel = new QLabel("MAh:",this);
    QLabel* hoursbatLabel = new QLabel("Durata Batteria:",this);
    cameraLabel = new QLabel("Fotocamera",this);
    QLabel* numcameraLabel = new QLabel("Numero:",this);
    QLabel* camerasensLabel = new QLabel("Sensore infrarossi:",this);
    QLabel* cameraflashLabel = new QLabel("Flash:",this);
    camerasecLabel = new QLabel("Fotocamera anteriore",this);
    QLabel* numseccameraLabel = new QLabel("Numero:",this);
    QLabel* camerasecsensLabel = new QLabel("Sensore infrarossi:",this);
    QLabel* camerasecflashLabel = new QLabel("Flash:",this);
    tastLabel = new QLabel("Tastiera",this);
    QLabel* tasttypeLabel = new QLabel("Tipo:",this);
    QLabel* tastillLabel = new QLabel("Retroilluminata:",this);
    schermoLabel = new QLabel("Schermo",this);
    QLabel* schermoresLabel = new QLabel("Risoluzione:",this);
    QLabel* schermosizeLabel = new QLabel("Dimensione:",this);
    QLabel* schermotecLabel = new QLabel("Tecnologia Schermo:",this);
    QLabel* nomeComputerLabel = new QLabel("Nome:",this);
    QLabel* coloreComputerLabel = new QLabel("Colore:",this);
    QLabel* prezzoComputerLabel = new QLabel("Prezzo:",this);
    QLabel* marcaComputerLabel = new QLabel("Marca:",this);
    QLabel* touchTabletLabel = new QLabel("Touch:",this);
    QLabel* multiTabletLabel = new QLabel("MultiTouch:",this);
    QLabel* pennaTabletLabel = new QLabel("Supporto Penna:",this);
    QLabel* weightPcLabel = new QLabel("Peso:",this);
    QLabel* tastTwoLabel = new QLabel("Tastiera removibile:",this);
    QLabel* wifiPhoneLabel = new QLabel("Wifi:",this);
    QLabel* gpsPhoneLabel = new QLabel("gps:",this);
    QLabel* touchPhoneLabel = new QLabel("touch:",this);
    QLabel* g3PhoneLabel = new QLabel("3G:",this);
    QLabel* g4PhoneLabel = new QLabel("4G:",this);
    QLabel* simPhoneLabel = new QLabel("Numero Sim:",this);
    QLabel* sdSmartLabel = new QLabel("Scheda SD:",this);
    QLabel* sensSmartLabel = new QLabel("Sensore di prossimità:",this);
    QLabel* multiSmartLabel = new QLabel("multitouch:",this);
    QLabel* pesoSmartLabel = new QLabel("Peso:",this);
    QLabel* scoccaSmartLabel = new QLabel("Materiale Scocca:",this);
    QLabel* osSmartLabel = new QLabel("Sistema operativo:",this);

    ramLayout->addWidget(ramnomeLabel);
    ramLayout->addWidget(nomeRam);
    ramLayout->addWidget(ramgbLabel);
    ramLayout->addWidget(gbRam);
    ramLayout->addWidget(ramtypeLabel);
    ramLayout->addWidget(typeRam);
    cpuLayout->addWidget(cpunomeLabel);
    cpuLayout->addWidget(nomeCPU);
    cpuLayout->addWidget(cpuclockLabel);
    cpuLayout->addWidget(clockCPU);
    cpuLayout->addWidget(cpugraphicLabel);
    cpuLayout->addWidget(graphicCPU);
    cpuLayout->addWidget(cpunomeLabel);
    cpuLayout->addWidget(nomeCPU);
    cpuLayout->addWidget(cpuclockLabel);
    cpuLayout->addWidget(clockCPU);
    coolLayout->addWidget(coolnomeLabel);
    coolLayout->addWidget(nomeCool);
    coolLayout->addWidget(cooltypeLabel);
    coolLayout->addWidget(typeCool);
    gpuLayout->addWidget(gpunomeLabel);
    gpuLayout->addWidget(nomeGPU);
    gpuLayout->addWidget(gpugbLabel);
    gpuLayout->addWidget(memorygpu);
    gpuLayout->addWidget(gpuclockLabel);
    gpuLayout->addWidget(clockgpu);
    hdLayout->addWidget(hddnomeLabel);
    hdLayout->addWidget(nomehdd);
    hdLayout->addWidget(hddgbLabel);
    hdLayout->addWidget(gbhdd);
    hdLayout->addWidget(hddtypeLabel);
    hdLayout->addWidget(typehdd);
    batLayout->addWidget(mahbatLabel);
    batLayout->addWidget(mahbat);
    batLayout->addWidget(hoursbatLabel);
    batLayout->addWidget(hours_bat);
    cameraLayout->addWidget(numcameraLabel);
    cameraLayout->addWidget(num_fotocamera);
    cameraLayout->addWidget(camerasensLabel);
    cameraLayout->addWidget(sensorefotocamera);
    cameraLayout->addWidget(cameraflashLabel);
    cameraLayout->addWidget(flashfotocamera);
    camerasecLayout->addWidget(numseccameraLabel);
    camerasecLayout->addWidget(num_secfotocamera);
    camerasecLayout->addWidget(camerasecsensLabel);
    camerasecLayout->addWidget(sensoresecfotocamera);
    camerasecLayout->addWidget(camerasecflashLabel);
    camerasecLayout->addWidget(flashsecfotocamera);
    tastieraLayout->addWidget(tasttypeLabel);
    tastieraLayout->addWidget(typetastiera);
    tastieraLayout->addWidget(tastillLabel);
    tastieraLayout->addWidget(retroilltast);
    schermoLayout->addWidget(schermoresLabel);
    schermoLayout->addWidget(resolutionschermo);
    schermoLayout->addWidget(schermosizeLabel);
    schermoLayout->addWidget(sizeschermo);
    schermoLayout->addWidget(schermotecLabel);
    schermoLayout->addWidget(tecSchermo);
    ComputerLayout->addWidget(coloreComputerLabel);
    ComputerLayout->addWidget(coloreComputer);
    ComputerLayout->addWidget(prezzoComputerLabel);
    ComputerLayout->addWidget(prezzoComputer);
    ComputerLayout->addWidget(marcaComputerLabel);
    ComputerLayout->addWidget(marcaComputer);
    TabletLayout->addWidget(touchTabletLabel);
    TabletLayout->addWidget(touchTablet);
    TabletLayout->addWidget(multiTabletLabel);
    TabletLayout->addWidget(multitouchTablet);
    TabletLayout->addWidget(pennaTabletLabel);
    TabletLayout->addWidget(pennaTablet);
    PCLayout->addWidget(weightPcLabel);
    PCLayout->addWidget(weightPC);
    TwoInOneLayout->addWidget(tastTwoLabel);
    TwoInOneLayout->addWidget(tastieraTwoInOne);
    PhoneLayout->addWidget(wifiPhoneLabel);
    PhoneLayout->addWidget(wifiPhone);
    PhoneLayout->addWidget(gpsPhoneLabel);
    PhoneLayout->addWidget(gpsPhone);
    PhoneLayout->addWidget(touchPhoneLabel);
    PhoneLayout->addWidget(touchPhone);
    PhoneLayout->addWidget(g3PhoneLabel);
    PhoneLayout->addWidget(g3Phone);
    PhoneLayout->addWidget(simPhoneLabel);
    PhoneLayout->addWidget(simPhone);
    Smart1Layout->addWidget(g4PhoneLabel);
    Smart1Layout->addWidget(g4Smart);
    Smart1Layout->addWidget(sdSmartLabel);
    Smart1Layout->addWidget(sdSmart);
    Smart1Layout->addWidget(sensSmartLabel);
    Smart1Layout->addWidget(sensoreSmart);
    Smart1Layout->addWidget(multiSmartLabel);
    Smart1Layout->addWidget(multitouchSmart);
    Smart2Layout->addWidget(pesoSmartLabel);
    Smart2Layout->addWidget(pesoSmart);
    Smart2Layout->addWidget(scoccaSmartLabel);
    Smart2Layout->addWidget(scoccaSmart);
    Smart2Layout->addWidget(osSmartLabel);
    Smart2Layout->addWidget(osSmart);

    mainLayout->addWidget(type);
    mainLayout->addWidget(nomeComputerLabel);
    mainLayout->addWidget(nomeComputer);
    mainLayout->addWidget(ramLabel);
    mainLayout->addLayout(ramLayout);
    mainLayout->addWidget(cpuLabel);
    mainLayout->addLayout(cpuLayout);
    mainLayout->addWidget(coolLabel);
    mainLayout->addLayout(coolLayout);
    mainLayout->addWidget(GPULabel);
    mainLayout->addLayout(gpuLayout);
    mainLayout->addWidget(HDDLabel);
    mainLayout->addLayout(hdLayout);
    mainLayout->addWidget(batLabel);
    mainLayout->addWidget(batContainer);
    mainLayout->addWidget(cameraLabel);
    mainLayout->addWidget(cameraContainer);
    mainLayout->addWidget(camerasecLabel);
    mainLayout->addWidget(camerasecContainer);
    mainLayout->addWidget(tastLabel);
    mainLayout->addWidget(tastContainer);
    mainLayout->addWidget(schermoLabel);
    mainLayout->addWidget(schermoContainer);
    mainLayout->addWidget(computerContainer);
    mainLayout->addWidget(tabletContainer);
    mainLayout->addWidget(pcContainer);
    mainLayout->addWidget(twoinoneContainer);
    mainLayout->addWidget(phoneContainer);
    mainLayout->addWidget(smartphone1Container);
    mainLayout->addWidget(smartphone2Container);
    connect(type,SIGNAL(currentTextChanged(const QString&)), this, SLOT(setType(const QString&)));
    emit(type->currentTextChanged(type->currentText()));
}

string AddItemWidget::getTipo() const
{
    return type->currentText().toStdString();
}

void AddItemWidget::setType(const QString&)
{
    QString s = type->currentText();
    batLabel->setVisible(false);
    schermoLabel->setVisible(false);
    tastLabel->setVisible(false);
    cameraLabel->setVisible(false);
    camerasecLabel->setVisible(false);
    batContainer->setVisible(false);
    schermoContainer->setVisible(false);
    tastContainer->setVisible(false);
    cameraContainer->setVisible(false);
    camerasecContainer->setVisible(false);
    tabletContainer->setVisible(false);
    pcContainer->setVisible(false);
    twoinoneContainer->setVisible(false);
    phoneContainer->setVisible(false);
    smartphone1Container->setVisible(false);
    smartphone2Container->setVisible(false);
    if (s == QString::fromStdString("Tablet"))
    {
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        tabletContainer->setVisible(true);
    }
    else if (s == QString::fromStdString("PC"))
    {
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        cameraLabel->setVisible(true);
        cameraContainer->setVisible(true);
        tastLabel->setVisible(true);
        tastContainer->setVisible(true);
        pcContainer->setVisible(true);
    }
    else if (s == QString::fromStdString("TwoInOne"))
    {
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        cameraLabel->setVisible(true);
        cameraContainer->setVisible(true);
        tabletContainer->setVisible(true);
        tastLabel->setVisible(true);
        tastContainer->setVisible(true);
        pcContainer->setVisible(true);
        twoinoneContainer->setVisible(true);
    }
    else if (s == QString::fromStdString("SmartPhone"))
    {
        schermoLabel->setVisible(true);
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        cameraLabel->setVisible(true);
        camerasecLabel->setVisible(true);
        cameraContainer->setVisible(true);
        camerasecContainer->setVisible(true);
        phoneContainer->setVisible(true);
        schermoContainer->setVisible(true);
        smartphone1Container->setVisible(true);
        smartphone2Container->setVisible(true);
    }
}

Ram* AddItemWidget::getRam() const {return new Ram(nomeRam->text().toStdString(),gbRam->text().toInt(),typeRam->text().toStdString());}

CPU* AddItemWidget::getCPU() const {return new CPU(nomeCPU->text().toStdString(),clockCPU->text().toDouble(),graphicCPU->text().toStdString());}

GPU* AddItemWidget::getGPU() const {return new GPU(nomeGPU->text().toStdString(),memorygpu->text().toInt(),clockgpu->text().toDouble());}

Cooling* AddItemWidget::getCool() const {return new Cooling(nomeCool->text().toStdString(),typeCool->text().toStdString());}

HardDisk* AddItemWidget::getHardDisk() const {return new HardDisk(nomehdd->text().toStdString(),gbhdd->text().toInt(),typehdd->text().toStdString());}

Battery* AddItemWidget::getBattery() const {return new Battery(mahbat->text().toInt(),gbRam->text().toInt());}

Fotocamera* AddItemWidget::getFotocamera() const {return new Fotocamera(num_fotocamera->text().toInt(),vector<int>(),(sensorefotocamera->checkState() == 2),(flashfotocamera->checkState() == 2));}

Schermo* AddItemWidget::getSchermo() const {return new Schermo(resolutionschermo->text().toStdString(),sizeschermo->text().toInt(),tecSchermo->text().toStdString());}

bool AddItemWidget::getretroTast() const {return retroilltast->checkState() == 2;}

string AddItemWidget::getTipoTast() const {return typetastiera->text().toStdString();}

string AddItemWidget::getNome() const {return nomeComputer->text().toStdString();}

string AddItemWidget::getColore() const {return coloreComputer->text().toStdString();}

string AddItemWidget::getMarca() const {return marcaComputer->text().toStdString();}

double AddItemWidget::getPrezzo() const {return prezzoComputer->text().toDouble();}

bool AddItemWidget::gettouchTablet() const {return touchTablet->checkState() == 2;}

bool AddItemWidget::getmultitouchTablet() const {return multitouchTablet->checkState() == 2;}

bool AddItemWidget::getPennaTablet() const {return pennaTablet->checkState() == 2;}

double AddItemWidget::getWeightPC() const {return weightPC->text().toDouble();}

bool AddItemWidget::getTastTwoInOne() const {return tastieraTwoInOne->checkState() == 2;}

bool AddItemWidget::getwifi() const {return wifiPhone->checkState() == 2;}

bool AddItemWidget::getGPS() const {return gpsPhone->checkState() == 2;}

bool AddItemWidget::getTouchPhone() const {return touchPhone->checkState() == 2;}

bool AddItemWidget::get3g() const {return g3Phone->checkState() == 2;}

int AddItemWidget::getSim() const {return simPhone->text().toInt();}

bool AddItemWidget::get4g() const {return g4Smart->checkState() == 2;}

bool AddItemWidget::getSensore() const {return sensoreSmart->checkState() == 2;}

bool AddItemWidget::getSd() const {return sdSmart->checkState() == 2;}

bool AddItemWidget::getmultitouchSmart() const {return multitouchSmart->checkState() == 2;}

double AddItemWidget::getPeso() const {return pesoSmart->text().toDouble();}

string AddItemWidget::getScocca() const {return scoccaSmart->text().toStdString();}

string AddItemWidget::getOS() const {return osSmart->text().toStdString();}
