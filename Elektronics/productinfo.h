#ifndef PRODUCTINFO_H
#define PRODUCTINFO_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>

class Computer;

class ProductInfo : public QWidget
{
    Q_OBJECT
private:
    Computer* item;
public:
    ProductInfo(Computer* i, QWidget* parent = nullptr);
    QLabel* type;
    QLineEdit* nomeRam;
    QLineEdit* gbRam;
    QLineEdit* typeRam;
    QLineEdit* nomeCPU;
    QLineEdit* clockCPU;
    QLineEdit* graphicCPU;
    QLineEdit* nomeCool;
    QLineEdit* typeCool;
    QLineEdit* nomeGPU;
    QLineEdit* memorygpu;
    QLineEdit* clockgpu;
    QLineEdit* nomehdd;
    QLineEdit* gbhdd;
    QLineEdit* typehdd;
    QLineEdit* mahbat;
    QLineEdit* hours_bat;
    QLineEdit* num_fotocamera;
    QCheckBox* sensorefotocamera;
    QCheckBox* flashfotocamera;
    QLineEdit* num_secfotocamera;
    QCheckBox* sensoresecfotocamera;
    QCheckBox* flashsecfotocamera;
    QCheckBox* retroilltast;
    QLineEdit* typetastiera;
    QLineEdit* resolutionschermo;
    QLineEdit* sizeschermo;
    QLineEdit* tecSchermo;
    QLineEdit* nomeComputer;
    QLineEdit* prezzoComputer;
    QLineEdit* coloreComputer;
    QLineEdit* marcaComputer;
    QCheckBox* touchTablet;
    QCheckBox* multitouchTablet;
    QCheckBox* pennaTablet;
    QLineEdit* weightPC;
    QCheckBox* tastieraTwoInOne;
    QCheckBox* wifiPhone;
    QCheckBox* gpsPhone;
    QCheckBox* touchPhone;
    QCheckBox* g3Phone;
    QLineEdit* simPhone;
    QCheckBox* g4Smart;
    QCheckBox* sdSmart;
    QCheckBox* sensoreSmart;
    QCheckBox* multitouchSmart;
    QLineEdit* pesoSmart;
    QLineEdit* scoccaSmart;
    QLineEdit* osSmart;
    QWidget* batContainer;
    QWidget* cameraContainer;
    QWidget* camerasecContainer;
    QWidget* schermoContainer;
    QWidget* tastContainer;
    QWidget* computerContainer;
    QWidget* tabletContainer;
    QWidget* pcContainer;
    QWidget* twoinoneContainer;
    QWidget* phoneContainer;
    QWidget* smartphone1Container;
    QWidget* smartphone2Container;
    QLabel*  batLabel;
    QLabel*  cameraLabel;
    QLabel*  camerasecLabel;
    QLabel*  tastLabel;
    QLabel* schermoLabel;
private slots:
    void save();
};

#endif // PRODUCTINFO_H
