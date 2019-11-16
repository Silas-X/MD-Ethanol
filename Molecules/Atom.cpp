#include "Atom.h"
#include <string>
using std::string;

AtomBase::AtomBase(int _typeNbr, ChargeType _charge, MassType _mass, NameType _name)
{
    typeNbr = _typeNbr;
    name = _name;
    charge = _charge;
    mass = _mass;
}

AtomBase::~AtomBase() {}

//Accessor
int AtomBase::GetTypeNbr() const { return typeNbr; }
NameType AtomBase::GetName() const { return name; }
ChargeType AtomBase::GetCharge() const { return charge; }
MassType AtomBase::GetMass() const { return mass; }

//Mutator

Atom::Atom(int typeNbr, ChargeType charge, MassType mass, Location pos, NameType name)
    : AtomBase(typeNbr, charge, mass, name), Location(pos){number++;};

Atom::~Atom(){};

int Atom::number = 0;