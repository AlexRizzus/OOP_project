
#include "items.h"

/*
 *
 *        COMPONENTI BASE
 *
 *
 */

//CLASSE BASE COMPONENT

//RANDOM ACCESS MEMORY
Ram::Ram(string n, int giga, string t) :
    nome(n), gb(giga), type(t)
{}

bool Ram::operator==(const Ram& c) const
{
    return (getNome() == c.getNome() && gb == c.getGb() && type == c.getType());
}

bool Ram::operator<=(const Ram& c) const
{
    return gb <= c.getGb();
}

bool Ram::operator>=(const Ram& c) const
{
    return gb <= c.getGb();
}

int Ram::getGb() const {return gb;}

string Ram::getType() const {return type;}

string Ram::getNome() const { return nome; }

void Ram::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Ram");
    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("gb");
    writer.writeCharacters(QString::fromStdString(std::to_string(getGb())));
    writer.writeEndElement();
    writer.writeStartElement("type");
    writer.writeCharacters(QString::fromStdString(getType()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Ram::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "gb")
        gb = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "type")
        type = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}


//PROCESSORE
CPU::CPU(string n, double cl, string gp): nome(n), clock(cl), graphic(gp) {}

bool CPU::operator==(const CPU&c) const
{
    return ( getNome()==c.getNome() && clock == c.getClock() && graphic == c.getGraphic());
}

bool CPU::operator<=(const CPU&c) const
{
    return (clock <= c.getClock());
}
bool CPU::operator>=(const CPU&c) const
{
    return (clock >= c.getClock());
}

double CPU::getClock() const {return clock;}

string CPU::getGraphic() const {return graphic;}

string CPU::getNome() const { return nome; }

void CPU::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("CPU");

    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("clock");
    writer.writeCharacters(QString::fromStdString(std::to_string(getClock())));
    writer.writeEndElement();
    writer.writeStartElement("graphic");
    writer.writeCharacters(QString::fromStdString(getGraphic()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void CPU::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "clock")
        clock = reader.readElementText().toDouble();
    if(reader.readNextStartElement() && reader.name() == "graphic")
        graphic = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}

//SISTEMA DI RAFFREDDAMENTO
Cooling::Cooling(string n, string t) : nome(n), type(t) {}

bool Cooling::operator==(const Cooling& c) const
{
    return (getNome() == c.getNome() && type == c.getType());
}

string Cooling::getType() const {return type;}

string Cooling::getNome() const { return nome; }

void Cooling::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Cooling");
    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("type");
    writer.writeCharacters(QString::fromStdString(getType()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Cooling::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "type")
        type = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}


//SCHEDA GRAFICA
GPU::GPU(string n, int mem, double cl): nome(n), memory(mem), clock(cl) {}

bool GPU::operator==(const GPU& c) const
{
    return (getNome() == c.getNome() && clock == c.getClock() && memory == c.getMemory());
}

bool GPU::operator<=(const GPU& c) const
{
    return memory <= c.getMemory();
}
bool GPU::operator>=(const GPU& c) const
{
    return memory >= c.getMemory();
}

int GPU::getMemory() const {return memory;}

double GPU::getClock() const {return clock;}

string GPU::getNome() const { return nome; }

void GPU::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("GPU");
    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("clock");
    writer.writeCharacters(QString::fromStdString(std::to_string(getClock())));
    writer.writeEndElement();
    writer.writeStartElement("memory");
    writer.writeCharacters(QString::fromStdString(std::to_string(getMemory())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void GPU::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "clock")
        clock = reader.readElementText().toDouble();
    if(reader.readNextStartElement() && reader.name() == "memory")
        memory = reader.readElementText().toInt();
    reader.skipCurrentElement();
}

//HARD DISK
HardDisk::HardDisk(string n, int giga, string t) : nome(n), gb(giga), type(t) {}

bool HardDisk::operator==(const HardDisk& c) const
{
    return (getNome() == c.getNome() && gb == c.getGb() && type == c.getType());
}
bool HardDisk::operator<=(const HardDisk& c) const
{
    return (gb <= c.getGb());
}
bool HardDisk::operator>=(const HardDisk& c) const
{
    return (gb >= c.getGb());
}

int HardDisk::getGb() const {return gb;}

string HardDisk::getType() const {return type;}

string HardDisk::getNome() const { return nome; }

void HardDisk::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("HDD");
    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("gb");
    writer.writeCharacters(QString::fromStdString(std::to_string(getGb())));
    writer.writeEndElement();
    writer.writeStartElement("type");
    writer.writeCharacters(QString::fromStdString(getType()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void HardDisk::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "gb")
        gb = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "type")
        type = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}

//BATTERY
Battery::Battery( int mAh, double bh): mAh(mAh), battery_hour(bh) {}

bool Battery::operator==(const Battery& c) const
{
    return (battery_hour == c.getBattery_hour() && mAh == c.getMAh());
}
bool Battery::operator<=(const Battery& c) const
{
    return mAh <= c.getMAh();
}
bool Battery::operator>=(const Battery& c) const
{
    return mAh >= c.getMAh();
}

int Battery::getMAh() const {return mAh;}

double Battery::getBattery_hour() const {return battery_hour;}

void Battery::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Battery");
    writer.writeStartElement("Mah");
    writer.writeCharacters(QString::fromStdString(std::to_string(getMAh())));
    writer.writeEndElement();
    writer.writeStartElement("hours");
    writer.writeCharacters(QString::fromStdString(std::to_string(getBattery_hour())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Battery::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "Mah")
        mAh = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "hours")
        battery_hour = reader.readElementText().toDouble();
    reader.skipCurrentElement();
}

//FOTOCAMERA
Fotocamera::Fotocamera(int num, vector<int> megap, bool infrarossi, bool f) : num_fotocamere(num), megapixel(megap), sensore_infrarossi(infrarossi), flash(f) {}

bool Fotocamera::operator==(const Fotocamera& c) const
{
    return (num_fotocamere == c.getNum_fotocamere() && megapixel == c.getMegapixel() && sensore_infrarossi == c.getSensore() && flash == c.getFlash());
}
bool Fotocamera::operator<=(const Fotocamera& c) const
{
    return num_fotocamere <= c.getNum_fotocamere();
}
bool Fotocamera::operator>=(const Fotocamera& c) const
{
    return num_fotocamere == c.getNum_fotocamere();
}

int Fotocamera::getNum_fotocamere() const {return num_fotocamere;}

vector<int> Fotocamera::getMegapixel() const {return megapixel;}

bool Fotocamera::getSensore() const {return sensore_infrarossi;}

bool Fotocamera::getFlash() const {return flash;}

void Fotocamera::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Fotocamera");

    writer.writeStartElement("Numero_Fotocamere");
    writer.writeCharacters(QString::fromStdString(std::to_string(getNum_fotocamere())));
    writer.writeEndElement();
    writer.writeStartElement("sensore");
    writer.writeCharacters(QString::fromStdString(std::to_string(getSensore())));
    writer.writeEndElement();
    writer.writeStartElement("flash");
    writer.writeCharacters(QString::fromStdString(std::to_string(getFlash())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Fotocamera::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "Numero_Fotocamere")
        num_fotocamere = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "sensore")
        sensore_infrarossi = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "flash")
        flash = reader.readElementText().toInt();
    reader.skipCurrentElement();
}
//TASTIERA
Tastiera::Tastiera(string t, bool retro): type(t), retroilluminata(retro) {}

string Tastiera::getType() const {return type;}

bool Tastiera::getretro() const {return retroilluminata;}

void Tastiera::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Tastiera");

    writer.writeStartElement("type");
    writer.writeCharacters(QString::fromStdString(getType()));
    writer.writeEndElement();
    writer.writeStartElement("retroill");
    writer.writeCharacters(QString::fromStdString(std::to_string(getretro())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Tastiera::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "type")
        type = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "retroill")
        retroilluminata = reader.readElementText().toInt();
    reader.skipCurrentElement();
}

//SCHERMO
Schermo::Schermo(string res, double s, string t): resolution(res), size(s), tec(t) {}

bool Schermo::operator==(const Schermo& s) const
{
    return (resolution == s.getResolution() && size == s.getSize() && tec == s.getTec());
}
string Schermo::getResolution() const {return resolution;}

double Schermo::getSize() const {return size;}

string Schermo::getTec() const {return tec;}

void Schermo::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Schermo");
    writer.writeStartElement("resolution");
    writer.writeCharacters(QString::fromStdString(getResolution()));
    writer.writeEndElement();
    writer.writeStartElement("size");
    writer.writeCharacters(QString::fromStdString(std::to_string(getSize())));
    writer.writeEndElement();
    writer.writeStartElement("tec");
    writer.writeCharacters(QString::fromStdString(getTec()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Schermo::read(QXmlStreamReader& reader)
{

    if(reader.readNextStartElement() && reader.name() == "resolution")
        resolution = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "size")
        size = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "tec")
        tec = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}

/*
 *
 *
 *
 *          GERARCHIA DELLE CLASSI PRODOTTI ELETTRONICI
 *
 *
 *
 */
//COMPUTER
Computer::Computer(string nom,Ram* r, CPU* c, GPU* g, HardDisk* hdd, Cooling* raf,double prez, string col, string mar) :nome(nom), ram(r), processore(c), graphic(g), HDD(hdd),raffreddamento(raf), prezzo(prez), colore(col), marca(mar)
{
}
Computer::Computer(const Computer& c)
{
	nome = c.nome;
    processore = new CPU(*c.processore);
    ram = new Ram(*c.ram);
    graphic = new GPU(*c.graphic);
    HDD = new HardDisk(*c.HDD);
    raffreddamento = new Cooling(*c.raffreddamento);
	prezzo = c.prezzo;
    colore = c.colore;
    marca = c.marca;
}
Computer::~Computer()
{
    delete ram;
    delete processore;
    delete graphic;
    delete HDD;
    delete raffreddamento;
}

bool Computer::operator==(const Computer& c) const
{
    return ( nome == c.getNome() && *ram == *c.getRam() && *processore == *c.getCPU() && *graphic == *c.getGPU() && *HDD == *c.getHDD() && *raffreddamento == *c.getraff() && prezzo == c.getPrezzo() && marca == c.getMarca() && colore == c.getColore());
}

Computer& Computer::operator=(const Computer& c)
{
    if (*this == c)
    {

    }
    else
    {
        delete ram;
        delete processore;
        delete graphic;
        delete HDD;
        delete raffreddamento;
        string s = c.getNome();
        nome = c.getNome();
        s = nome;
        ram = new Ram(*c.getRam());
        processore = new CPU(*c.getCPU());
        graphic = new GPU(*c.getGPU());
        HDD = new HardDisk(*c.getHDD());
        raffreddamento = new Cooling(*c.getraff());
        prezzo = c.getPrezzo();
        colore = c.getColore();
        marca = c.getMarca();
    }
    return *this;
}
Ram* Computer::getRam() const { return ram;}

CPU* Computer::getCPU() const {return processore;}

GPU* Computer::getGPU() const {return graphic;}

HardDisk* Computer::getHDD() const {return HDD;}

Cooling* Computer::getraff() const {return raffreddamento;}

double Computer::getPrezzo() const {return prezzo;}

string Computer::getNome() const {return nome;}

string Computer::getColore() const {return colore;}

string Computer::getMarca() const {return marca;}

string Computer::getTipo() const {return "computer";}

Computer* Computer::clone() const {return new Computer(*this);}

void Computer::setRam(Ram* r)
{
    delete ram;
    ram = r;
}

void Computer::setCPU(CPU* c)
{
    delete processore;
    processore = c;
}

void Computer::setGPU(GPU* g)
{
    delete graphic;
    graphic = g;
}

void Computer::setHDD(HardDisk* h)
{
    delete HDD;
    HDD = h;
}

void Computer::setCool(Cooling* r)
{
    delete raffreddamento;
    raffreddamento = r;
}

void Computer::setPrezzo(double p)
{
    prezzo = p;
}

void Computer::setNome(string n)
{
    nome = n;
}

void Computer::setColore(string c)
{
    colore = c;
}

void Computer::setMarca(string m)
{
    marca = m;
}

void Computer::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("COMPUTER");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));
    ram->write(writer);
    processore->write(writer);
    graphic->write(writer);
    HDD->write(writer);
    raffreddamento->write(writer);
    writer.writeStartElement("nome");
    writer.writeCharacters(QString::fromStdString(getNome()));
    writer.writeEndElement();
    writer.writeStartElement("prezzo");
    writer.writeCharacters(QString::fromStdString(std::to_string(getPrezzo())));
    writer.writeEndElement();
    writer.writeStartElement("colore");
    writer.writeCharacters(QString::fromStdString(getColore()));
    writer.writeEndElement();
    writer.writeStartElement("marca");
    writer.writeCharacters(QString::fromStdString(getMarca()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Computer::read(QXmlStreamReader& reader)
{
   if(reader.readNextStartElement() && reader.name() == "Ram")
       ram->read(reader);
   if(reader.readNextStartElement() && reader.name() == "CPU")
       processore->read(reader);
   if(reader.readNextStartElement() && reader.name() == "GPU")
       graphic->read(reader);
   if(reader.readNextStartElement() && reader.name() == "HDD")
       HDD->read(reader);
   if(reader.readNextStartElement() && reader.name() == "Cooling")
       raffreddamento->read(reader);
    if(reader.readNextStartElement() && reader.name() == "nome")
        nome = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "prezzo")
        prezzo = reader.readElementText().toDouble();
    if(reader.readNextStartElement() && reader.name() == "colore")
        colore = reader.readElementText().toStdString();
    if(reader.readNextStartElement() && reader.name() == "marca")
        marca = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}

//TABLET
Tablet::Tablet(string nom,Ram* r, CPU* c, GPU* g, HardDisk* hdd, Cooling* raf,double prez, string col, string mar,Battery* b, bool t, bool multit, bool pen): Computer(nom,r,c,g,hdd,raf,prez,col,mar), bat(b), touch(t), multitouch(multit), penna(pen)
{

}

Tablet::Tablet(const Tablet& t)
{
    Computer::operator=(t);
    bat = new Battery(*t.getBattery());
    touch = t.getTouch();
    multitouch = t.getmultitouch();
    penna = t.getPenna();
}

Tablet::~Tablet()
{
    delete bat;
}

Tablet& Tablet::operator=(const Tablet& t)
{
    if (*this == t)
    {

    }
    else
    {
        delete bat;
        Computer::operator=(t);
        bat = new Battery(*t.getBattery());
        touch = t.getTouch();
        multitouch = t.getmultitouch();
        penna = t.getPenna();
    }
    return *this;
}

Battery* Tablet::getBattery() const { return bat; }

bool Tablet::getTouch() const {return touch;}

bool Tablet::getmultitouch() const {return multitouch;}

bool Tablet::getPenna() const {return penna;}

string Tablet::getTipo() const {return "tablet";}

bool Tablet::operator==(const Tablet& t) const
{
    return (Computer::operator==(t) && *bat == *t.getBattery() && touch == t.getTouch() && multitouch == t.getmultitouch() && penna == t.getPenna());
}

Computer* Tablet::clone() const {return new Tablet(*this);}

void Tablet::setBattery(Battery* b)
{
    delete bat;
    bat = b;
}

void Tablet::setTouch(bool t)
{
    touch = t;
}

void Tablet::setMultiTouch(bool m)
{
    multitouch = m;
}

void Tablet::setPenna(bool p)
{
    penna = p;
}

void Tablet::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Tablet");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));

    Computer::write(writer);
    bat->write(writer);
    writer.writeStartElement("touch");
    writer.writeCharacters(QString::fromStdString(std::to_string(getTouch())));
    writer.writeEndElement();
    writer.writeStartElement("multitouch");
    writer.writeCharacters(QString::fromStdString(std::to_string(getmultitouch())));
    writer.writeEndElement();
    writer.writeStartElement("penna");
    writer.writeCharacters(QString::fromStdString(std::to_string(getPenna())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Tablet::read(QXmlStreamReader& reader)
{
   if (reader.readNextStartElement() && reader.name() == "COMPUTER")
       Computer::read(reader);
   if(reader.readNextStartElement() && reader.name() == "Battery")
       bat->read(reader);
    if(reader.readNextStartElement() && reader.name() == "touch")
        touch = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "multitouch")
        multitouch = reader.readElementText().toInt();
    if(reader.readNextStartElement() && reader.name() == "penna")
        penna = reader.readElementText().toInt();
    reader.skipCurrentElement();
}


//PERSONAL COMPUTER
PC::PC(string nom,Ram* r, CPU* c, GPU* g, HardDisk* hdd, Cooling* raf,double prez, string col, string mar, Battery* b, double w, Tastiera* t, Fotocamera* web) : Computer(nom,r,c,g,hdd,raf,prez,col,mar), bat(b), weight(w), tast(t), webcam(web)
{

}

PC::PC(const PC& p)
{
    Computer::operator=(p);
    bat = new Battery(*p.getBattery());
    weight = p.getWeight();
    tast = new Tastiera(*p.getTastiera());
    webcam = new Fotocamera(*p.getWebcam());
}

PC::~PC()
{
    delete bat;
    delete tast;
    delete webcam;
}
PC& PC::operator=(const PC& p)
{
    if (*this == p)
    {

    }
    else
    {
        delete bat;
        delete tast;
        delete webcam;
        Computer::operator=(p);
        bat = new Battery(*p.getBattery());
        weight = p.getWeight();
        tast = new Tastiera(*p.getTastiera());
        webcam = new Fotocamera(*p.getWebcam());
    }

    return *this;
}

bool PC::operator==(const PC& p) const
{
    return (Computer::operator==(p) && *bat == *p.getBattery() && weight == p.getWeight() && tast == p.getTastiera() && webcam == p.getWebcam());
}

Battery* PC::getBattery() const {return bat;}

double PC::getWeight() const {return weight;}

Tastiera* PC::getTastiera() const {return tast;}

Fotocamera* PC::getWebcam() const{return webcam;}

string PC::getTipo() const {return "pc";}

Computer* PC::clone() const {return new PC(*this);}

void PC::setBattery(Battery* b)
{
    delete bat;
    bat = b;
}

void PC::setWeight(double w)
{
    weight = w;
}

void PC::setTastiera(Tastiera* t)
{
    delete tast;
    tast = t;
}

void PC::setFotocamera(Fotocamera* f)
{
    delete webcam;
    webcam = f;
}

void PC::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("PC");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));

    if (getTipo() == "pc")
    {
        Computer::write(writer);
        bat->write(writer);
    }
    writer.writeStartElement("weight");
    writer.writeCharacters(QString::fromStdString(std::to_string(getWeight())));
    writer.writeEndElement();
    tast->write(writer);
    webcam->write(writer);
    writer.writeEndElement();
}

void PC::read(QXmlStreamReader& reader)
{
    if (getTipo() == "pc")
    {
        if (reader.readNextStartElement() && reader.name() == "COMPUTER")
            Computer::read(reader);
        if(reader.readNextStartElement() && reader.name() == "Battery")
            bat->read(reader);
    }
    if(reader.readNextStartElement() && reader.name() == "weight")
        weight = reader.readElementText().toDouble();
    if(reader.readNextStartElement() && reader.name() == "Tastiera")
       tast->read(reader);
    if(reader.readNextStartElement() && reader.name() == "Fotocamera")
       webcam->read(reader);
    reader.skipCurrentElement();
}


//TWOINONE
TwoInOne::TwoInOne(string nom,Ram* r, CPU* c, GPU* g, HardDisk* hdd, Cooling* raf,double prez, string col, string mar, Battery* bat, double w, Tastiera* t, Fotocamera* web, bool touch, bool multit, bool pen, bool tast):Computer (nom,r,c,g,hdd,raf,prez,col,mar), PC(nom, r, c, g, hdd, raf, prez, col, mar,new Battery(bat->getMAh(),bat->getBattery_hour()), w, t, web), Tablet(nom, r, c, g, hdd, raf, prez, col, mar, bat, touch, multit, pen), tastiera(tast)
{

}

TwoInOne::TwoInOne(const TwoInOne& t)
{
    PC::operator=(t);
    Tablet::operator=(t);
    tastiera = t.getTastiera();
}

TwoInOne& TwoInOne::operator=(const TwoInOne& t)
{
    if (*this == t)
    {

    }
    else
    {
        PC::operator=(t);
        Tablet::operator=(t);
        tastiera = t.getTastiera();
    }
    return *this;
}

bool TwoInOne::operator==(const TwoInOne& t) const
{
    return ( PC::operator==(t) && Tablet::operator==(t) && tastiera == t.getTastiera());
}

bool TwoInOne::getTastiera() const {return tastiera;}

string TwoInOne::getTipo() const {return "twoinone";}

Computer* TwoInOne::clone() const {return new TwoInOne(*this);}

void TwoInOne::setTastiera(bool t) {tastiera = t;}

void TwoInOne::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("TwoInOne");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));
    Tablet::write(writer);
    PC::write(writer);
    writer.writeStartElement("tastiera");
    writer.writeCharacters(QString::fromStdString(std::to_string(getTastiera())));
    writer.writeEndElement();
    writer.writeEndElement();

}

void TwoInOne::read(QXmlStreamReader& reader)
{
    if(reader.readNextStartElement() && reader.name() == "Tablet")
        Tablet::read(reader);
    if(reader.readNextStartElement() && reader.name() == "PC")
        PC::read(reader);
    if(reader.readNextStartElement() && reader.name() == "tastiera")
        tastiera = reader.readElementText().toInt();
    reader.skipCurrentElement();
}


//TELEFONO
Telefono::Telefono(Battery* b, bool wifi, int sim, bool gps, Fotocamera* f, Fotocamera* p, bool t, bool g3): bat(b), wifi(wifi), sim(sim), GPS(gps), front(f), post(p), touch(t), g3(g3)
{

}

Telefono::Telefono(const Telefono& t)
{
    bat = new Battery(*t.getBattery());
    wifi = t.getWiFi();
    sim = t.getSim();
    GPS = t.getGPS();
    front = new Fotocamera(*t.getFrontFot());
    post = new Fotocamera(*t.getPostFot());
    touch = t.getTouch();
    g3 = t.get3g();
}

Telefono::~Telefono()
{
    delete bat;
    delete front;
    delete post;
}

Telefono& Telefono::operator=(const Telefono& t)
{
    if (*this == t)
    {

    }
    else
    {
        bat = new Battery(*t.getBattery());
        wifi = t.getWiFi();
        sim = t.getSim();
        GPS = t.getGPS();
        front = new Fotocamera(*t.getFrontFot());
        post = new Fotocamera(*t.getPostFot());
        touch = t.getTouch();
        g3 = t.get3g();
    }

    return *this;
}

bool Telefono::operator==(const Telefono& t) const
{
    return (*bat == *t.getBattery() && wifi == t.getWiFi() && sim == t.getSim() && *front == *t.getFrontFot() && *post == *t.getPostFot() && touch == t.getTouch() && g3 == t.get3g());
}

Battery* Telefono::getBattery() const {return bat;}

bool Telefono::getWiFi() const {return wifi;}

int Telefono::getSim() const {return sim;}

bool Telefono::getGPS() const {return GPS;}

Fotocamera* Telefono::getFrontFot() const {return front;}

Fotocamera* Telefono::getPostFot() const {return post;}

bool Telefono::getTouch() const {return touch;}

bool Telefono::get3g() const {return g3;}

void Telefono::setBattery(Battery* b)
{
    delete bat;
    bat = b;
}

void Telefono::setWifi(bool w) {wifi = w;}

void Telefono::setSim(int s) {sim = s;}

void Telefono::setGPS(bool g) {GPS = g;}

void Telefono::setFrontFot(Fotocamera* f)
{
    delete front;
    front = f;
}

void Telefono::setPostFot(Fotocamera* p)
{
    delete post;
    post = p;
}

void Telefono::setTouch(bool t) {touch = t;}

void Telefono::set3g(bool g) {g3 = g;}

void Telefono::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("Telefono");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));
    bat->write(writer);
    writer.writeStartElement("wifi");
    writer.writeCharacters(QString::fromStdString(std::to_string(getWiFi())));
    writer.writeEndElement();
    writer.writeStartElement("sim");
    writer.writeCharacters(QString::fromStdString(std::to_string(getSim())));
    writer.writeEndElement();
    writer.writeStartElement("gps");
    writer.writeCharacters(QString::fromStdString(std::to_string(getGPS())));
    writer.writeEndElement();
    front->write(writer);
    post->write(writer);
    writer.writeStartElement("touch");
    writer.writeCharacters(QString::fromStdString(std::to_string(getTouch())));
    writer.writeEndElement();
    writer.writeStartElement("g3");
    writer.writeCharacters(QString::fromStdString(std::to_string(get3g())));
    writer.writeEndElement();
    writer.writeEndElement();
}

void Telefono::read(QXmlStreamReader& reader)
{
    if(reader.readNextStartElement() && reader.name() == "Battery")
        bat->read(reader);
     if(reader.readNextStartElement() && reader.name() == "wifi")
         wifi = reader.readElementText().toInt();
     if(reader.readNextStartElement() && reader.name() == "sim")
         sim = reader.readElementText().toInt();
     if(reader.readNextStartElement() && reader.name() == "gps")
         GPS = reader.readElementText().toInt();
     if (reader.readNextStartElement() && reader.name() == "Fotocamera")
     front->read(reader);
     if (reader.readNextStartElement() && reader.name() == "Fotocamera")
     post->read(reader);
     if(reader.readNextStartElement() && reader.name() == "touch")
         touch = reader.readElementText().toInt();
     if(reader.readNextStartElement() && reader.name() == "g3")
         g3 = reader.readElementText().toInt();
     reader.skipCurrentElement();
}

//SMARTPHONE
SmartPhone::SmartPhone(string nom,Ram* r, CPU* c, GPU* g, HardDisk* hdd, Cooling* raf,double prez, string col, string mar, Battery* b, bool wifi, int sim, bool gps, Fotocamera* f, Fotocamera* p, bool t, bool g4, bool sd, bool sens, Schermo* sc, bool mt, double peso, string scocca, string os): Telefono(b,wifi,sim,gps,f,p,t,true), Computer(nom,r,c,g,hdd,raf,prez,col,mar), g4(g4), sd(sd), sensore_di_prox(sens), display(sc), multitouch(mt), peso(peso), scocca(scocca), sistema_operativo(os)
{

}

SmartPhone::SmartPhone(const SmartPhone& s)
{
    Computer::operator=(s);
    Telefono::operator=(s);
    g4 = s.get4g();
    sd = s.getSd();
    sensore_di_prox = s.getSensore();
    display = new Schermo(*s.getSchermo());
    multitouch = s.getMultitouch();
    peso = s.getPeso();
    scocca = s.getScocca();
    sistema_operativo = s.getOS();
}

SmartPhone::~SmartPhone()
{
    delete display;
}

SmartPhone& SmartPhone::operator=(const SmartPhone& s)
{
    if (*this == s)
    {

    }
    else
    {
        Computer::operator=(s);
        Telefono::operator=(s);
        g4 = s.get4g();
        sd = s.getSd();
        sensore_di_prox = s.getSensore();
        display = new Schermo(*s.getSchermo());
        multitouch = s.getMultitouch();
        peso = s.getPeso();
        scocca = s.getScocca();
        sistema_operativo = s.getOS();
    }
    return *this;
}

bool SmartPhone::operator==(const SmartPhone& s) const
{
    return (Computer::operator==(s) && Telefono::operator==(s) && g4 == s.get4g() && sd == s.getSd() && sensore_di_prox == s.getSensore() && *display == *s.getSchermo() && multitouch == s.getMultitouch() && peso == s.getPeso() && scocca == s.getScocca() && sistema_operativo == s.getOS());
}

bool SmartPhone:: get4g() const {return g4;}

bool SmartPhone::getSd() const {return sd;}

bool SmartPhone::getSensore() const {return sensore_di_prox;}

Schermo* SmartPhone::getSchermo() const {return display;}

bool SmartPhone::getMultitouch() const {return multitouch;}

double SmartPhone::getPeso() const {return peso;}

string SmartPhone::getScocca() const {return scocca;}

string SmartPhone::getOS() const {return sistema_operativo;}

string SmartPhone::getTipo() const {return "smartphone";}

Computer* SmartPhone::clone() const {return new SmartPhone(*this);}

void SmartPhone::set4g(bool g) {g4 = g;}

void SmartPhone::setSd(bool s) {sd = s;}

void SmartPhone::setSensore(bool s) {sensore_di_prox = s;}

void SmartPhone::setSchermo(Schermo * s)
{
    delete display;
    display = s;
}

void SmartPhone::setMultitouch(bool m) {multitouch = m;}

void SmartPhone::setPeso(double p) {peso = p;}

void SmartPhone::setScocca(string s) {scocca = s;}

void SmartPhone::setOS(string o) {sistema_operativo = o;}

void SmartPhone::write(QXmlStreamWriter& writer) const
{
    writer.writeStartElement("SmartPhone");
    writer.writeAttribute("type",QString::fromStdString(getTipo()));
    Telefono::write(writer);
    Computer::write(writer);
    writer.writeStartElement("g4");
    writer.writeCharacters(QString::fromStdString(std::to_string(get4g())));
    writer.writeEndElement();
    writer.writeStartElement("sd");
    writer.writeCharacters(QString::fromStdString(std::to_string(getSd())));
    writer.writeEndElement();
    display->write(writer);
    writer.writeStartElement("multitouch");
    writer.writeCharacters(QString::fromStdString(std::to_string(getMultitouch())));
    writer.writeEndElement();
    writer.writeStartElement("peso");
    writer.writeCharacters(QString::fromStdString(std::to_string(getPeso())));
    writer.writeEndElement();
    writer.writeStartElement("scocca");
    writer.writeCharacters(QString::fromStdString(getScocca()));
    writer.writeEndElement();
    writer.writeStartElement("OS");
    writer.writeCharacters(QString::fromStdString(getOS()));
    writer.writeEndElement();
    writer.writeEndElement();
}

void SmartPhone::read(QXmlStreamReader& reader)
{
    if(reader.readNextStartElement() && reader.name() == "Telefono")
        Telefono::read(reader);
    if(reader.readNextStartElement() && reader.name() == "COMPUTER")
        Computer::read(reader);
     if(reader.readNextStartElement() && reader.name() == "g4")
         g4 = reader.readElementText().toInt();
     if(reader.readNextStartElement() && reader.name() == "sd")
         sd = reader.readElementText().toInt();
     if(reader.readNextStartElement() && reader.name() == "Schermo")
          display->read(reader);
     if(reader.readNextStartElement() && reader.name() == "multitouch")
         multitouch = reader.readElementText().toInt();
     if (reader.readNextStartElement() && reader.name() == "peso")
        peso = reader.readElementText().toDouble();
     if (reader.readNextStartElement() && reader.name() == "scocca")
        scocca = reader.readElementText().toStdString();
     if(reader.readNextStartElement() && reader.name() == "os")
         sistema_operativo = reader.readElementText().toStdString();
    reader.skipCurrentElement();
}
