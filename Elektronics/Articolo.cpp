#include "articolo.h"

articolo::articolo(Computer* t) : p(t)
{

}
articolo::~articolo()
{
    if(p)
    delete p;
}

articolo::articolo(const articolo& a)
{
    p = new Computer(*a);
}
articolo& articolo::operator=(const articolo& a)
{
    if(&a != this)
    {
        if(p != a.p && p != nullptr)
		{
			delete p;
		}
        p = a->clone();
    }
    string s = p->getNome();
    return *this;
}
Computer& articolo::operator*() const
{
    return *p;
}

Computer* articolo::operator->() const
{
    return p;
}
