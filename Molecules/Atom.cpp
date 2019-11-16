#include "Atom.h"
#include <string>
using std::string;

AtomBase::AtomBase(ChargeType _charge, MassType _mass, NameType _name)
{
    name = _name;
    charge = _charge;
    mass = _mass;
}
AtomBase::AtomBase(const AtomBase &origin)
{
    // this->mass = origin.mass;
    //this->charge = origin.charge;
    //this->name = origin.name;
    *this = origin;
}
AtomBase::~AtomBase() {}

//Accessor
NameType AtomBase::GetName() const { return name; }
ChargeType AtomBase::GetCharge() const { return charge; }
MassType AtomBase::GetMass() const { return mass; }

//Mutator

bool AtomBase::SetCharge(const double charge)
{
    this->charge= charge;
    return true;
}
AtomBase &AtomBase::operator=(const AtomBase &origin)
{
    if (this == &origin)
        return *this;
    this->mass = origin.mass;
    this->charge = origin.charge;
    this->name = origin.name;
    return *this;
}

Atom::Atom(int _typeNbr, ChargeType charge, MassType mass, Location pos, NameType name)
    : typeNbr(_typeNbr), AtomBase(charge, mass, name), Location(pos)
{
    number++;
};

Atom::~Atom(){};

int Atom::GetTypeNbr() const { return typeNbr; }
int Atom::number = 0;
