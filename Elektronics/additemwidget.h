#ifndef ADDITEMWIDGET_H
#define ADDITEMWIDGET_H

#include <QComboBox>
#include <string>
#include <QLineEdit>
#include <QCheckBox>
#include <QBoxLayout>
#include <QWidget>
#include <QLabel>
#include<items.h>

using namespace std;

class AddItemWidget : public QWidget
{
    Q_OBJECT
private:
    QComboBox* type;
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


public:
    AddItemWidget(QWidget* parent = nullptr);
    string getTipo() const;
    Ram* getRam() const;
    CPU* getCPU() const;
    GPU* getGPU() const;
    Cooling* getCool() const;
    HardDisk* getHardDisk() const;
    Battery* getBattery() const;
    Fotocamera* getFotocamera() const;
    Schermo* getSchermo() const;
    bool getretroTast() const;
    string getTipoTast() const;
    string getNome() const;
    double getPrezzo() const;
    string getColore() const;
    string getMarca() const;
    bool gettouchTablet() const;
    bool getmultitouchTablet() const;
    bool getPennaTablet() const;
    double getWeightPC() const;
    bool getTastTwoInOne() const;
    bool getwifi() const;
    bool getGPS() const;
    bool getTouchPhone() const;
    bool get3g() const;
    int getSim() const;
    bool get4g() const;
    bool getSd() const;
    bool getSensore() const;
    bool getmultitouchSmart() const;
    double getPeso() const;
    string getScocca() const;
    string getOS() const;

private slots:
    void setType(const QString&);



};

#endif // ADDITEMWIDGET_H
