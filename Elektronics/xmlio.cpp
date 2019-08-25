#include "xmlio.h"

#include <QFile>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>

XmlIO::XmlIO(const string& path) : filename(path)
{

}


void XmlIO::write(const Container<articolo>& container) const
{
    QSaveFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::WriteOnly))
        throw std::exception();
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeComment("Elektronics");
    writer.writeStartElement("root");
    auto cit = container.begin();
    while (cit != container.end())
    {
        (*cit)->write(writer);
        cit++;
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    file.commit();


}

Container<articolo> XmlIO::read() const
{
    Container<articolo> con;
    QFile file(QString::fromStdString(filename));
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox box(QMessageBox::Warning, "Errore","Impossibile aprire il file selezionato",QMessageBox::Ok);
    }
    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement() && reader.name() == "root"){
        while(reader.readNextStartElement()) {
            string s = reader.attributes().value("type").toString().toStdString();
            Computer* p = nullptr;
            if (s == "computer")
            {
                p = new Computer();
                p->read(reader);
            }
            if (s == "tablet")
            {
                p = new Tablet();
                p->read(reader);
            }
            if (s == "pc")
            {
               p = new PC();
               p->read(reader);
            }
            if (s == "twoinone")
            {
                p = new TwoInOne();
                p->read(reader);
            }
            if (s == "smartphone")
            {
                p = new SmartPhone();
                p->read(reader);
            }
            articolo a = articolo(p);
            con.insertEl(a);
            a.p = nullptr;
        }
    }
    file.close();
    return con;
}
