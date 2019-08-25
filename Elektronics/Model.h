#ifndef MODEL_H
#define MODEL_H
#include "container.h"
#include "articolo.h"

class Model
{
private:
    Container<articolo> container;
public:
    Model();
    unsigned int getSize() const;
    void add(articolo&);
    Computer* getElement(int);
    void remove(unsigned int);
    Container<articolo>::iteratore& begin() const;
    void save(const string&) const;
    void load(const string&);
};

#endif // MODEL_H
