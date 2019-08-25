#include "productinfo.h"
#include "items.h"
#include "QBoxLayout"
#include <QPushButton>
#include <QCheckBox>
using std::string;

ProductInfo::ProductInfo(Computer* i, QWidget* parent) :
QWidget(parent), item(i),
 type(new QLabel( QString::fromStdString(item->getTipo()),this)),
 nomeRam(new QLineEdit(QString::fromStdString(item->getRam()->getNome()),this)),
 gbRam(new QLineEdit(QString::fromStdString(std::to_string(item->getRam()->getGb())),this)), typeRam(new QLineEdit(QString::fromStdString(item->getRam()->getType()),this)),
 nomeCPU(new QLineEdit(QString::fromStdString(item->getCPU()->getNome()),this)), clockCPU(new QLineEdit(QString::fromStdString(std::to_string(item->getCPU()->getClock())),this)), graphicCPU(new QLineEdit(QString::fromStdString(item->getCPU()->getGraphic()),this)),
 nomeCool(new QLineEdit(QString::fromStdString(item->getraff()->getNome()),this)), typeCool(new QLineEdit(QString::fromStdString(item->getraff()->getType()),this)),
 nomeGPU(new QLineEdit(QString::fromStdString(item->getGPU()->getNome()),this)), memorygpu(new QLineEdit(QString::fromStdString(std::to_string(item->getGPU()->getMemory())),this)), clockgpu(new QLineEdit(QString::fromStdString(std::to_string(item->getGPU()->getClock())),this)),
 nomehdd(new QLineEdit(QString::fromStdString(item->getHDD()->getNome()),this)), gbhdd(new QLineEdit(QString::fromStdString(std::to_string(item->getHDD()->getGb())),this)), typehdd(new QLineEdit(QString::fromStdString(item->getHDD()->getType()),this))
{

    setFixedSize(700,900);
    type->setStyleSheet("font-size : 30px;");
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
    QLabel* cpuclockLabel = new QLabel("Clock speed (GHz):",this);
    QLabel* cpugraphicLabel = new QLabel("Scheda grafica:",this);
    QLabel* cpunomeLabel = new QLabel("Nome:",this);
    QLabel* coolLabel = new QLabel("Sistema di Raffreddamento",this);
    QLabel* coolnomeLabel = new QLabel("Nome:",this);
    QLabel* cooltypeLabel = new QLabel("Tipo:",this);
    QLabel* GPULabel = new QLabel("Scheda Grafica",this);
    QLabel* gpunomeLabel = new QLabel("Nome:",this);
    QLabel* gpugbLabel = new QLabel("GBytes:",this);
    QLabel* gpuclockLabel = new QLabel("Clock speed (GHz):",this);
    QLabel* HDDLabel = new QLabel("Memoria",this);
    QLabel* hddnomeLabel = new QLabel("Nome:",this);
    QLabel* hddgbLabel = new QLabel("Memoria (GBytes):",this);
    QLabel* hddtypeLabel = new QLabel("Tipo:",this);
    batLabel = new QLabel("Batteria",this);
    QLabel* mahbatLabel = new QLabel("MAh:",this);
    QLabel* hoursbatLabel = new QLabel("Durata Batteria (h):",this);
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
    QLabel* schermosizeLabel = new QLabel("Dimensione (\"):",this);
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
    QLabel* pesoSmartLabel = new QLabel("Peso (gr):",this);
    QLabel* scoccaSmartLabel = new QLabel("Materiale Scocca:",this);
    QLabel* osSmartLabel = new QLabel("Sistema operativo:",this);
    mahbat = new QLineEdit(this);
    hours_bat = new QLineEdit(this);
    num_fotocamera = new QLineEdit(this);
    sensorefotocamera = new QCheckBox(this);
    flashfotocamera = new QCheckBox(this);
    num_secfotocamera = new QLineEdit(this);
    sensoresecfotocamera = new QCheckBox(this);
    flashsecfotocamera = new QCheckBox(this);
    retroilltast = new QCheckBox(this);
    typetastiera = new QLineEdit(this);
    resolutionschermo = new QLineEdit(this);
    sizeschermo = new QLineEdit(this);
    tecSchermo = new QLineEdit(this);
    nomeComputer = new QLineEdit(this);
    touchTablet = new QCheckBox(this);
    multitouchTablet = new QCheckBox(this);
    pennaTablet = new QCheckBox(this);
    weightPC = new QLineEdit(this);
    tastieraTwoInOne = new QCheckBox(this);
    wifiPhone = new QCheckBox(this);
    simPhone = new QLineEdit(this);
    gpsPhone = new QCheckBox(this);
    touchPhone = new QCheckBox(this);
    g3Phone = new QCheckBox(this);
    g4Smart = new QCheckBox(this);
    sdSmart = new QCheckBox(this);
    sensoreSmart = new QCheckBox(this);
    multitouchSmart = new QCheckBox(this);
    pesoSmart = new QLineEdit(this);
    scoccaSmart= new QLineEdit(this);
    osSmart = new QLineEdit(this);

    mahbat->setVisible(false);
    hours_bat->setVisible(false);
    num_fotocamera->setVisible(false);
    sensorefotocamera->setVisible(false);
    flashfotocamera->setVisible(false);
    num_secfotocamera->setVisible(false);
    sensoresecfotocamera->setVisible(false);
    flashsecfotocamera->setVisible(false);
    retroilltast->setVisible(false);
    typetastiera->setVisible(false);
    resolutionschermo->setVisible(false);
    sizeschermo->setVisible(false);
    tecSchermo->setVisible(false);
    nomeComputer->setVisible(false);
    touchTablet->setVisible(false);
    multitouchTablet->setVisible(false);
    pennaTablet->setVisible(false);
    weightPC->setVisible(false);
    tastieraTwoInOne->setVisible(false);
    wifiPhone->setVisible(false);
    simPhone->setVisible(false);
    gpsPhone->setVisible(false);
    touchPhone->setVisible(false);
    g3Phone->setVisible(false);
    g4Smart->setVisible(false);
    sdSmart->setVisible(false);
    sensoreSmart->setVisible(false);
    multitouchSmart->setVisible(false);
    pesoSmart->setVisible(false);
    scoccaSmart->setVisible(false);
    osSmart->setVisible(false);


    string s = item->getTipo();

    if (s == "tablet")
    {

        Tablet* t = dynamic_cast<Tablet*>(item);
        mahbat = new QLineEdit(QString::fromStdString(std::to_string(t->getBattery()->getMAh())),this);
        mahbat->font().bold();
        hours_bat = new QLineEdit(QString::fromStdString(std::to_string(t->getBattery()->getBattery_hour())),this);
        if (t->getTouch())
        touchTablet->setCheckState(Qt::Checked);
        if (t->getmultitouch())
        multitouchTablet->setCheckState(Qt::Checked);
        if (t->getPenna())
        pennaTablet->setCheckState(Qt::Checked);
        mahbat->setVisible(true);
        hours_bat->setVisible(true);
        touchTablet->setVisible(true);
        multitouchTablet->setVisible(true);
        pennaTablet->setVisible(true);
    }
    if (s == "pc")
    {
        PC* p = dynamic_cast<PC*>(item);

        mahbat = new QLineEdit(QString::fromStdString(std::to_string(p->getBattery()->getMAh())), this);
        hours_bat = new QLineEdit(QString::fromStdString(std::to_string(p->getBattery()->getBattery_hour())),this);
        if (p->getTastiera()->getretro())
        retroilltast->setCheckState(Qt::Checked);
        typetastiera = new QLineEdit(QString::fromStdString(p->getTastiera()->getType()), this);
        num_fotocamera = new QLineEdit(QString::fromStdString(std::to_string(p->getWebcam()->getNum_fotocamere())),this);
        if (p->getWebcam()->getSensore())
        sensorefotocamera->setCheckState(Qt::Checked);
        if (p->getWebcam()->getFlash())
        flashfotocamera->setCheckState(Qt::Checked);
        weightPC = new QLineEdit(QString::fromStdString(std::to_string(p->getWeight())), this);
        mahbat->setVisible(true);
        hours_bat->setVisible(true);
        retroilltast->setVisible(true);
        typetastiera->setVisible(true);
        num_fotocamera->setVisible(true);
        sensorefotocamera->setVisible(true);
        flashfotocamera->setVisible(true);
        weightPC->setVisible(true);
    }
    if (s == "twoinone")
    {

        TwoInOne* t = dynamic_cast<TwoInOne*>(item);
        mahbat = new QLineEdit(QString::fromStdString(std::to_string(t->Tablet::getBattery()->getMAh())),this);
        hours_bat = new QLineEdit(QString::fromStdString(std::to_string(t->Tablet::getBattery()->getBattery_hour())),this);
        if (t->getTouch())
        touchTablet->setCheckState(Qt::Checked);
        if (t->getmultitouch())
        multitouchTablet->setCheckState(Qt::Checked);
        if (t->getPenna())
        pennaTablet->setCheckState(Qt::Checked);
        if (t->PC::getTastiera()->getretro())
        retroilltast->setCheckState(Qt::Checked);
        typetastiera = new QLineEdit(QString::fromStdString(t->PC::getTastiera()->getType()), this);
        num_fotocamera = new QLineEdit(QString::fromStdString(std::to_string(t->getWebcam()->getNum_fotocamere())),this);
        if (t->getWebcam()->getSensore())
        sensorefotocamera->setCheckState(Qt::Checked);
        if (t->getWebcam()->getFlash())
        flashfotocamera->setCheckState(Qt::Checked);
        if (t->getTastiera())
        tastieraTwoInOne->setCheckState(Qt::Checked);
        mahbat->setVisible(true);
        hours_bat->setVisible(true);
        retroilltast->setVisible(true);
        typetastiera->setVisible(true);
        num_fotocamera->setVisible(true);
        sensorefotocamera->setVisible(true);
        flashfotocamera->setVisible(true);
        weightPC->setVisible(true);
        touchTablet->setVisible(true);
        multitouchTablet->setVisible(true);
        pennaTablet->setVisible(true);
        tastieraTwoInOne->setVisible(true);
    }

    if (s == "smartphone")
    {

        SmartPhone* s = dynamic_cast<SmartPhone*>(item);
        mahbat = new QLineEdit(QString::fromStdString(std::to_string(s->getBattery()->getMAh())),this);
        hours_bat = new QLineEdit(QString::fromStdString(std::to_string(s->getBattery()->getBattery_hour())),this);
        num_fotocamera = new QLineEdit(QString::fromStdString(std::to_string(s->getPostFot()->getNum_fotocamere())),this);
        if (s->getPostFot()->getSensore())
        sensorefotocamera->setCheckState(Qt::Checked);
        if (s->getPostFot()->getFlash())
        flashfotocamera->setCheckState(Qt::Checked);
        num_secfotocamera = new QLineEdit(QString::fromStdString(std::to_string(s->getFrontFot()->getNum_fotocamere())),this);
        if (s->getFrontFot()->getSensore())
        sensoresecfotocamera->setCheckState(Qt::Checked);
        if (s->getFrontFot()->getFlash())
        flashsecfotocamera->setCheckState(Qt::Checked);
        sizeschermo = new QLineEdit(QString::fromStdString(std::to_string(s->getSchermo()->getSize())), this);
        resolutionschermo = new QLineEdit(QString::fromStdString(s->getSchermo()->getResolution()), this);
        tecSchermo = new QLineEdit(QString::fromStdString(s->getSchermo()->getTec()), this);
        if (s->getWiFi())
        wifiPhone->setCheckState(Qt::Checked);
        simPhone = new QLineEdit(QString::fromStdString(std::to_string(s->getSim())), this);
        if (s->getGPS())
        gpsPhone->setCheckState(Qt::Checked);
        if (s->get3g())
        g3Phone->setCheckState(Qt::Checked);
        if (s->get4g())
        g4Smart->setCheckState(Qt::Checked);
        if (s->getSd())
        sdSmart->setCheckState(Qt::Checked);
        if (s->getSensore())
        sensoreSmart->setCheckState(Qt::Checked);
        if (s->getMultitouch())
        multitouchSmart->setCheckState(Qt::Checked);
        if(s->getTouch())
        touchPhone->setCheckState(Qt::Checked);
        pesoSmart = new QLineEdit(QString::fromStdString(std::to_string(s->getPeso())), this);
        scoccaSmart = new QLineEdit(QString::fromStdString(s->getScocca()), this);
        osSmart = new QLineEdit(QString::fromStdString(s->getOS()), this);
        mahbat->setVisible(true);
        hours_bat->setVisible(true);
        num_fotocamera->setVisible(true);
        sensorefotocamera->setVisible(true);
        flashfotocamera->setVisible(true);
        num_secfotocamera->setVisible(true);
        sensoresecfotocamera->setVisible(true);
        flashsecfotocamera->setVisible(true);
        resolutionschermo->setVisible(true);
        sizeschermo->setVisible(true);
        tecSchermo->setVisible(true);
        wifiPhone->setVisible(true);
        simPhone->setVisible(true);
        gpsPhone->setVisible(true);
        touchPhone->setVisible(true);
        g3Phone->setVisible(true);
        g4Smart->setVisible(true);
        sdSmart->setVisible(true);
        sensoreSmart->setVisible(true);
        multitouchSmart->setVisible(true);
        pesoSmart->setVisible(true);
        scoccaSmart->setVisible(true);
        osSmart->setVisible(true);
    }
    nomeComputer = new QLineEdit(QString::fromStdString(item->getNome()), this);
    nomeComputer->setStyleSheet("font-size: 16px");
    marcaComputer = new QLineEdit(QString::fromStdString(item->getMarca()), this);
    prezzoComputer = new QLineEdit(QString::fromStdString(std::to_string(item->getPrezzo())), this);
    coloreComputer = new QLineEdit(QString::fromStdString(item->getColore()),this);
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
    if (s == "tablet")
    {
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        tabletContainer->setVisible(true);
    }
    else if (s == "pc")
    {
        batLabel->setVisible(true);
        batContainer->setVisible(true);
        cameraLabel->setVisible(true);
        cameraContainer->setVisible(true);
        tastLabel->setVisible(true);
        tastContainer->setVisible(true);
        pcContainer->setVisible(true);
    }
    else if (s == "twoinone")
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
    else if (s == "smartphone")
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
    QPushButton* saveButton = new QPushButton("Salva", this);
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    mainLayout->addLayout(buttonLayout);
    connect(saveButton, SIGNAL(clicked()),this, SLOT(save()));

}


void ProductInfo::save()
{
    item->setRam(new Ram(nomeRam->text().toStdString(),gbRam->text().toInt(),typeRam->text().toStdString()));
    item->setCPU(new CPU(nomeCPU->text().toStdString(),clockCPU->text().toDouble(),graphicCPU->text().toStdString()));
    item->setGPU(new GPU(nomeGPU->text().toStdString(),memorygpu->text().toInt(),clockgpu->text().toDouble()));
    item->setCool(new Cooling(nomeCool->text().toStdString(), typeCool->text().toStdString()));
    item->setHDD(new HardDisk(nomehdd->text().toStdString(), gbhdd->text().toInt(), typehdd->text().toStdString()));
    item->setColore(coloreComputer->text().toStdString());
    item->setPrezzo(marcaComputer->text().toDouble());
    item->setMarca(marcaComputer->text().toStdString());
    item->setNome(nomeComputer->text().toStdString());
    string s = item->getTipo();
    if (s == "tablet")
    {
        Tablet* t = dynamic_cast<Tablet*>(item);
        t->setBattery(new Battery(mahbat->text().toInt(), hours_bat->text().toDouble()));
        t->setTouch(touchTablet->isChecked());
        t->setMultiTouch(multitouchTablet->isChecked());
        t->setPenna(pennaTablet->isChecked());
    }
    if (s == "pc")
    {
        PC* p = dynamic_cast<PC*>(item);
        p->setBattery(new Battery(mahbat->text().toInt(), hours_bat->text().toDouble()));
        p->setTastiera(new Tastiera(typetastiera->text().toStdString(),retroilltast->isChecked()));
        p->setFotocamera(new Fotocamera(num_fotocamera->text().toInt(),vector<int>(),sensorefotocamera->isChecked(),flashfotocamera->isChecked()));
        p->setWeight(weightPC->text().toDouble());
    }
    if (s == "twoinone")
    {
        TwoInOne* t = dynamic_cast<TwoInOne*>(item);
        t->Tablet::setBattery(new Battery(mahbat->text().toInt(), hours_bat->text().toDouble()));
        t->setTouch(touchTablet->isChecked());
        t->setMultiTouch(multitouchTablet->isChecked());
        t->setPenna(pennaTablet->isChecked());
        t->PC::setTastiera(new Tastiera(typetastiera->text().toStdString(),retroilltast->isChecked()));
        t->setFotocamera(new Fotocamera(num_fotocamera->text().toInt(),vector<int>(),sensorefotocamera->isChecked(),flashfotocamera->isChecked()));
        t->setWeight(weightPC->text().toDouble());
        t->setTastiera(tastieraTwoInOne->isChecked());
    }
    if (s == "smartphone")
    {
        SmartPhone* s = dynamic_cast<SmartPhone*>(item);
        s->setBattery(new Battery(mahbat->text().toInt(), hours_bat->text().toDouble()));
        s->setWifi(wifiPhone->isChecked());
        s->setSim(simPhone->text().toInt());
        s->setGPS(gpsPhone->isChecked());
        s->setTouch(touchPhone->isChecked());
        s->set3g(g3Phone->isChecked());
        s->set4g(g4Smart->isChecked());
        s->setSd(sdSmart->isChecked());
        s->setSensore(sensoreSmart->isChecked());
        s->setMultitouch(multitouchSmart->isChecked());
        s->setSchermo(new Schermo(resolutionschermo->text().toStdString(), sizeschermo->text().toDouble(), tecSchermo->text().toStdString()));
        s->setPeso(pesoSmart->text().toDouble());
        s->setScocca(scoccaSmart->text().toStdString());
        s->setOS(osSmart->text().toStdString());
    }
}
