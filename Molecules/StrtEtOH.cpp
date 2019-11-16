/* DONE: 
 *      Main Function
 * TODO: 
 *      Create atom function
 * 
 */
#include "StrtEtOH.h"
using space::dir;

Location GetAbsoluteLocation(Location origin, int offset)
{
    double x = origin.x + dir[offset].x;
    double y = origin.y + dir[offset].y;
    double z = origin.z + dir[offset].z;
    return (Location{x, y, z});
}

StrtEtOH::StrtEtOH(Location pos) : Location(pos)
{
    //Create Bone chain

    AtomBase _C1 = BasicAtoms::C;
    _C1.SetCharge(-0.17999999999999999);
    Create(C1,1, _C1, GetLocation());

    AtomBase _C2 = BasicAtoms::C;
    _C2.SetCharge(0.14499999999999999);
    Create(C2,2, _C2, GetAbsoluteLocation(C1->GetLocation(), 5));

    AtomBase _O = BasicAtoms::O;
    Create(O,3, _O, GetAbsoluteLocation(C2->GetLocation(), 5));

    //Create Hydrogen
    AtomBase _H1 = BasicAtoms::H;
    for (int i = 0; i < 3; i++)
    {
        Create(H1[i],4, _H1, GetAbsoluteLocation(C1->GetLocation(), i));
    }

    AtomBase _H2 = BasicAtoms::H;
    for (int i = 0; i < 2; i++)
    {
        Create(H2[i],5, _H2, GetAbsoluteLocation(C2->GetLocation(), i));
    }

    AtomBase _H3 = BasicAtoms::H;
    Create(H3, 6,_H3, GetAbsoluteLocation(O->GetLocation(), 5));
}

StrtEtOH::~StrtEtOH()
{
    delete C1;
    delete C2;
    delete O;
    delete[] H1;
    delete[] H2;
    delete H3;
}

bool StrtEtOH::Create(Atom *atom,const int typeNbr ,const AtomBase &base, const Location &pos)
{
    atom = new Atom{typeNbr,base, pos};
}