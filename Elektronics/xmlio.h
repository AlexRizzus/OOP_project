#ifndef XMLIO_H
#define XMLIO_H

#include <string>
#include <model.h>

using std::string;

class XmlIO
{
private:
    string filename;
public:
    XmlIO(const string&);
    Container<articolo> read() const;
    void write(const Container<articolo>&) const;
};

#endif // XMLIO_H
