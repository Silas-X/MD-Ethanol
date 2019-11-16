/* 
 * TODO: Provide basic data for C,H,O
 * 
 * 
*/
#ifndef ATOM_H
#define ATOM_H
#include <string>
#include <map>
#include "../SpaceParameter/Space.h"
using std::map;
using std::string;
using namespace space;

typedef double ChargeType;
typedef double MassType;
typedef string NameType;

class AtomBase
{
protected:
    MassType mass;
    ChargeType charge;
    NameType name;

public:
    AtomBase(ChargeType, MassType, NameType);
    AtomBase(const AtomBase &origin);
    ~AtomBase();

    NameType GetName() const;
    ChargeType GetCharge() const;
    MassType GetMass() const;

    bool SetCharge(const double charge);
    AtomBase &operator=(const AtomBase &origin);
};

class Atom : public AtomBase, public Location
{
protected:
    int typeNbr;
    //int groupNbr;
    static int number;

public:
    //Constructor
    Atom(int, ChargeType, MassType, Location, NameType);
    Atom(int,AtomBase, Location);
    //Destructor
    ~Atom();
    //Accessor
    int GetTypeNbr() const;
    //Mutator
};
namespace BasicAtoms
{
AtomBase C{0.14499999999999999, 12.0116, "C"};
AtomBase H{0.059999999999999998, 1.00794, "H"};
AtomBase O{-0.68300000000000005, 15.9994, "O"};

} // namespace BasicAtoms
#endif //ATOM_H