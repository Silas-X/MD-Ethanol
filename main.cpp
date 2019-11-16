#include <iostream>
#include <string>
#include <fstream>



int main()
{
    init();//initial in out files
    box{x,y,z}; //Simulation Box Environments
    molecular EtOH;//Simulation Atoms
    box.create();
    box.insert(EtOH);

}