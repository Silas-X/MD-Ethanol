#ifndef STRTETOH_H
#define STRTETOH_H
#include <string>
#include <map>
#include "Atom.h"

using namespace space;

class StrtEtOH : Location
{
private:
    Atom *C1, *C2, (*H1)[3], (*H2)[2], *O, *H3;
    bool Create(Atom *atom,const int typeNbr,const AtomBase &base, const Location &pos);
    int groupNbr;
public:
    StrtEtOH(Location pos);
    ~StrtEtOH();
};

#endif STRTETOH_H