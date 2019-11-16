#ifndef ATOM_H
#define ATOM_H
#include <string>
#include "../SpaceParameter/Space.h"
using std::string;
using namespace space;

typedef double ChargeType;
typedef double MassType;
typedef string NameType;

class AtomBase
{
protected:
    int typeNbr;
    MassType mass;
    ChargeType charge;
    NameType name;

public:
    AtomBase(int, ChargeType, MassType, NameType);
    ~AtomBase();

    int GetTypeNbr() const;
    NameType GetName() const;
    ChargeType GetCharge() const;
    MassType GetMass() const;
};

class Atom : public AtomBase, public Location
{
protected:
    //int groupNbr;
    static int number;
public:
    //Constructor
    Atom(int, ChargeType, MassType, Location, NameType);
    //Destructor
    ~Atom();
    //Accessor
    //Mutator
};
#endif //ATOM_H