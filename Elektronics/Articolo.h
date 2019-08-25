#ifndef ARTICOLO_H
#define ARTICOLO_H

#include "items.h"
enum bollino { convenienza, prestazioni, rapporto};
enum categoria {computer, telefono, tablet, dueinuno, pc, smartPhone};
enum caratteristica {RAM, Cpu, HD, Gpu, Tastiera};
class articolo
{
public:
    Computer* p;
    articolo(Computer* = new Computer());
    ~articolo();
    articolo(const articolo&);
    articolo& operator=(const articolo&);
    Computer& operator*() const;
    Computer* operator->() const;
};
#endif // ARTICOLO_H
