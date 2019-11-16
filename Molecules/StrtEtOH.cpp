#include "StrtEtOH.h"
using space::dir;


Location GetAbsouleLocation(Location origin, int offset)
{
    double x = origin.x + dir[offset].x;
    double y = origin.y + dir[offset].y;
    double z = origin.z + dir[offset].z;
    return (Location{x, y, z});
}

StrtEtOH::StrtEtOH(Location pos) : Location(pos)
{
    //Create Bone chain
    Create(C1, GetLocation());
    Create(C2, GetAbsouleLocation(C1->GetLocation(), 5));
    Create(O, GetAbsouleLocation(C2->GetLocation(), 5));

    //Create Hydrogen
    for (int i = 0; i < 3; i++)
    {
        Create(H1[i], GetAbsouleLocation(C1->GetLocation(), i));
    }
    for (int i = 0; i < 2; i++)
    {
        Create(H2[i], GetAbsouleLocation(C2->GetLocation(), i));
    }    
    Create(H3, GetAbsouleLocation(O->GetLocation(), 5));
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

bool StrtEtOH::Create(Atom* atom,Location pos)
{
    
}