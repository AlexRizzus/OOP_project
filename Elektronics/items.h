#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <string>
#include <vector>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
using std::string;
using std::vector;

class Ram {
private:
	string nome;
    int gb;
    string type;
public:
    Ram(string n = "indefinito", int giga = 0, string t = "indefinito");
    bool operator==(const Ram& c) const;
    bool operator<=(const Ram& c) const;
    bool operator>=(const Ram& c) const;
	string getNome() const;
    int getGb() const;
    string getType() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class CPU{
private:
	string nome;
    double clock;
    string graphic;
public:
    CPU(string n = "indefinito", double cl = 0, string gp = "non presente");
    bool operator==(const CPU& c) const;
    bool operator<=(const CPU& c) const;
    bool operator>=(const CPU& c) const;
	string getNome() const;
    double getClock() const;
    string getGraphic() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Cooling
{
private:
	string nome;
    string type;
public:
    Cooling(string n = "indefinito", string type = "aria");
    bool operator==(const Cooling& c) const;
	string getNome() const;
    string getType() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);

};

class GPU
{
private:
	string nome;
    int memory;
    double clock;
public:
    GPU(string n = "indefinito", int mem = 0, double cl = 0);
    bool operator==(const GPU& c) const;
    bool operator<=(const GPU& c) const;
    bool operator>=(const GPU& c) const;
	string getNome() const;
    int getMemory() const;
    double getClock() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class HardDisk{
private:
	string nome;
    int gb;
    string type;
public:
    HardDisk(string n = "indefinito", int giga = 0, string type = "Metal Disk");
    bool operator==(const HardDisk& c) const;
    bool operator<=(const HardDisk& c) const;
    bool operator>=(const HardDisk& c) const;
	string getNome() const;
    int getGb() const;
    string getType() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Battery
{
private:
    int mAh;
    double battery_hour;
public:
    Battery(int mAh = 0, double bh = 0);
    bool operator==(const Battery& c) const;
    bool operator<=(const Battery& c) const;
    bool operator>=(const Battery& c) const;
    int getMAh() const;
    double getBattery_hour() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Fotocamera
{
private:
    int num_fotocamere;
    vector<int> megapixel;
    bool sensore_infrarossi;
    bool flash;
public:
    Fotocamera(int num = 0, vector<int> megap = vector<int>(), bool infrarossi = false, bool f = false);
    bool operator==(const Fotocamera& c) const;
    bool operator<=(const Fotocamera& c) const;
    bool operator>=(const Fotocamera& c) const;
    int getNum_fotocamere() const;
    vector<int> getMegapixel() const;
    bool getSensore() const;
    bool getFlash() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Tastiera
{
private:
    string type;
    bool retroilluminata;
public:
    Tastiera(string t = "meccanica", bool retro = false);
    bool operator==(Fotocamera& c) const;
    bool operator<=(Fotocamera& c) const;
    bool operator>=(Fotocamera& c) const;
    string getType() const;
    bool getretro() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Schermo
{
private:
    string resolution;
    double size;
    string tec;
public:
    Schermo(string res = "0x0", double s = 0.0, string t = "IPS");
    bool operator==(const Schermo& s) const;
    string getResolution() const;
    double getSize() const;
    string getTec() const;
    void write(QXmlStreamWriter&) const;
    void read(QXmlStreamReader&);
};

class Computer
{
private:
    string nome;
    Ram* ram;
    CPU* processore;
    GPU* graphic;
    HardDisk* HDD;
    Cooling* raffreddamento;
    double prezzo;
    string colore;
    string marca;
public:
    Computer(string nom = "Computer", Ram* r = new Ram(), CPU* c = new CPU(), GPU* g =new GPU(), HardDisk* hdd = new HardDisk(), Cooling* raf = new Cooling() ,double prez = 0, string col = "none", string mar = "none");
    Computer(const Computer& c);
	virtual ~Computer();
    Ram* getRam() const;
    CPU* getCPU() const;
    GPU* getGPU() const;
    HardDisk* getHDD() const;
    Cooling* getraff() const;
    double getPrezzo() const;
    string getNome() const;
    string getColore() const;
    string getMarca() const;
    virtual string getTipo() const;
    void setRam(Ram*);
    void setCPU(CPU*);
    void setGPU(GPU*);
    void setHDD(HardDisk*);
    void setCool(Cooling*);
    void setPrezzo(double);
    void setNome(string);
    void setColore(string);
    void setMarca(string);
    Computer& operator=(const Computer&);
    bool operator ==(const Computer&) const;
    bool operator >=(Computer&) const;
    bool operator <=(Computer&) const;
    virtual Computer* clone() const;
    virtual void write(QXmlStreamWriter&) const;
    virtual void read(QXmlStreamReader&);
};

class Tablet : virtual public Computer
{
private:
    Battery* bat;
    bool touch;
    bool multitouch;
    bool penna;
public:
    Tablet(string nom = "Tablet", Ram* r = new Ram(), CPU* c = new CPU(), GPU* g =new GPU(), HardDisk* hdd = new HardDisk(), Cooling* raf = new Cooling() ,double prez = 0, string col = "none", string mar = "none", Battery* b = new Battery(), bool t = true, bool multit = false, bool pen = false);
    Tablet(const Tablet& t);
    virtual ~Tablet() override;
    Battery* getBattery() const;
    bool getTouch() const;
    bool getmultitouch() const;
    bool getPenna() const;
    string getTipo() const override;
    void setBattery(Battery*);
    void setTouch(bool);
    void setMultiTouch(bool);
    void setPenna(bool);
    bool operator ==(const Tablet&) const;
    Tablet& operator=(const Tablet&);
    Computer* clone() const override;
    virtual void write(QXmlStreamWriter&) const override;
    virtual void read(QXmlStreamReader&) override;
};

class PC : virtual public Computer
{
private:

    Battery* bat;
    double weight;
    Tastiera* tast;
    Fotocamera* webcam;
public:
    PC(string nom = "PC", Ram* r = new Ram(), CPU* c = new CPU(), GPU* g =new GPU(), HardDisk* hdd = new HardDisk(), Cooling* raf = new Cooling() ,double prez = 0, string col = "none", string mar = "none", Battery* bat = new Battery(),double weight = 0.0, Tastiera* t = new Tastiera(), Fotocamera* cam = new Fotocamera());
    PC(const PC& p);
    virtual ~PC() override;
    Battery* getBattery() const;
    double getWeight() const;
    Tastiera* getTastiera() const;
    Fotocamera* getWebcam() const;
    string getTipo() const override;
    void setBattery(Battery*);
    void setWeight(double);
    void setTastiera(Tastiera*);
    void setFotocamera(Fotocamera*);
    bool operator ==(const PC&) const;
    PC& operator=(const PC&);
    Computer* clone() const override;
    virtual void write(QXmlStreamWriter&) const override;
    virtual void read(QXmlStreamReader&) override;
};

class TwoInOne : public PC, public Tablet
{
private:
    bool tastiera;
public:
    TwoInOne(string nom = "TwoInOne", Ram* r = new Ram(), CPU* c = new CPU(), GPU* g =new GPU(), HardDisk* hdd = new HardDisk(), Cooling* raf = new Cooling() ,double prez = 0, string col = "none", string mar = "none", Battery* bat = new Battery(),double weight = 0.0, Tastiera* t = new Tastiera(), Fotocamera* cam = new Fotocamera(), bool touch = true, bool multit = false, bool pen = false, bool tast = false);
    TwoInOne(const TwoInOne& t);
    virtual ~TwoInOne() override = default;
    bool getTastiera() const;
    string getTipo() const override;
    void setTastiera(bool);
    bool operator==(const TwoInOne&) const;
    TwoInOne& operator=(const TwoInOne&);
    Computer* clone() const override final;
    virtual void write(QXmlStreamWriter&) const override;
    virtual void read(QXmlStreamReader&) override;
};

class Telefono
{
private:
    Battery* bat;
    bool wifi;
    int sim;
    bool GPS;
    Fotocamera* front;
    Fotocamera* post;
    bool touch;
    bool g3;
public:
    Telefono(Battery* b = new Battery(), bool wifi = false, int sim = 1, bool gps = false, Fotocamera* f = new Fotocamera(), Fotocamera* p = new Fotocamera(), bool t = false, bool g3 = false);
    Telefono(const Telefono& t);
    virtual ~Telefono();
    Battery* getBattery() const;
    bool getWiFi() const;
    int getSim() const;
    bool getGPS() const;
    Fotocamera* getFrontFot() const;
    Fotocamera* getPostFot() const;
    bool getFlash() const;
    bool getTouch() const;
    bool get3g() const;
    virtual string getTipo() const = 0;
    void setBattery(Battery*);
    void setWifi(bool);
    void setSim(int);
    void setGPS(bool);
    void setFrontFot(Fotocamera*);
    void setPostFot(Fotocamera*);
    void setTouch(bool);
    void set3g(bool);
    bool operator==(const Telefono&) const;
    Telefono& operator=(const Telefono&);
    virtual Computer* clone() const = 0;
    virtual void write(QXmlStreamWriter&) const;
    virtual void read(QXmlStreamReader&);
};

class SmartPhone : public Telefono, public Computer
{
private:
    bool g4;
    bool sd;
    bool sensore_di_prox;
    Schermo* display;
    bool multitouch;
    double peso;
    string scocca;
    string sistema_operativo;
public:
    SmartPhone(string nom = "Smartphone", Ram* r = new Ram(), CPU* c = new CPU(), GPU* g =new GPU(), HardDisk* hdd = new HardDisk(), Cooling* raf = new Cooling() ,double prez = 0, string col = "none", string mar = "none", Battery* b = new Battery(), bool wifi = false, int sim = 1, bool gps = false, Fotocamera* f = new Fotocamera(), Fotocamera* p = new Fotocamera(), bool t = false, bool g4 = false, bool sd = false, bool sens = true,Schermo* sc = new Schermo(), bool mt = true, double peso = 0.0, string scocca = "plastica", string os = "undefined");
    SmartPhone(const SmartPhone& s);
    virtual ~SmartPhone() override;
    bool get4g() const;
    bool getSd() const;
    bool getSensore() const;
    Schermo* getSchermo() const;
    bool getMultitouch() const;
    double getPeso() const;
    string getScocca() const;
    string getOS() const;
    string getTipo() const override;
    void set4g(bool);
    void setSd(bool);
    void setSensore(bool);
    void setSchermo(Schermo*);
    void setMultitouch(bool);
    void setPeso(double);
    void setScocca(string);
    void setOS(string);
    bool operator==(const SmartPhone&) const;
    SmartPhone& operator=(const SmartPhone&);
    Computer* clone() const override;
    virtual void write(QXmlStreamWriter&) const override;
    virtual void read(QXmlStreamReader&) override;
};


#endif // ITEMS_H
