#include "model.h"
#include "xmlio.h"

Model::Model() : container(Container<articolo>())
{}

unsigned int Model::getSize() const
{
    return container.getSize();
}

void Model::add(articolo& art)
{
    container.insertEl(art);
}

Computer* Model::getElement(int i)
{
    return container[i].operator->();
}


void Model::remove(unsigned int i)
{
    container.removeEl(i);
}

Container<articolo>::iteratore& Model::begin() const
{
    return container.begin();
}


void Model::save(const string& filename) const {
    XmlIO xmlio(filename);
    xmlio.write(container);
}

void Model::load(const string& filename) {
    container = Container<articolo>();
    XmlIO xmlio(filename);
    container = xmlio.read();
}

/*
 * articolo* piuconveniente(const Container<articolo>& con)
{
    Container<articolo>::iteratore it = con.begin();
    double min = con[it]->getPrezzo();
    articolo* artmin = &con[it];
    it++;
    for(int i = 1; i<con.getSize();i++)
    {
        if ((con[it])->getPrezzo() < min)
        {
            min = (con[it])->getPrezzo();
            artmin = &con[it];
        }
        it++;
    }
    return artmin;
}

articolo* performanceMigliori(const Container<articolo>& con)
{
    Container<articolo>::iteratore it = con.begin();
    CPU MaxPerformance = (*it)->getCPU();
    articolo* max = &con[it];
    for(int i = 0; i < con.getSize(); i++)
    {
        if (MaxPerformance.getClock() < (*it)->getCPU().getClock())
        {
            max = &con[it];
            MaxPerformance = (*it)->getCPU();
        }
    }
    return max;
}

Container<articolo>& ComputerByCPU(const CPU& c, Container<articolo>& con)
{
    Container<articolo> result = Container<articolo>();
    Container<articolo>::iteratore it = con.begin();
    for(it; it != con.end(); it++)
    {
        if(!((*it)->getCPU() == c))
        {
            result.insertEl(*it);
        }
    }
    return result;
}

Container<articolo>& ComputerByRAM(const Ram& r, Container<articolo>& con)
{
    Container<articolo> result = Container<articolo>();
    Container<articolo>::iteratore it = con.begin();
    for(it; it != con.end(); it++)
    {
        if(!((*it)->getRam() == r))
        {
            result.insertEl(*it);
        }
    }
    return result;
}

Container<articolo>& ComputerByGPU(const GPU& g, Container<articolo>& con)
{
    Container<articolo> result = Container<articolo>();
    Container<articolo>::iteratore it = con.begin();
    for(it; it != con.end(); it++)
    {
        if(!((*it)->getGPU() == g))
        {
           result.insertEl(*it);
        }
    }
    return result;
}

Container<articolo>& NewEntries(const Container<articolo>& con)
{
    Container<articolo> result = Container<articolo>();
    Container<articolo>::iteratore it = con.begin();
    for(it; it != con.end(); ++it)
    {
        if ((*it).news)
        {
            result.insertEl(*it);
        }
    }
    return result;
}

Container<articolo>& OfferteDelGiorno(const Container<articolo>& con)
{
    Container<articolo> result = Container<articolo>();
    Container<articolo>::iteratore it = con.begin();
    for(it; it != con.end(); it++)
    {
        if((*it).offerta)
        {
           result.insertEl(*it);
        }
    }
    return result;
}

 */
