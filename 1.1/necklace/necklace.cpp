/**
ID: samk641
LANG: C++
PROB: beads
 **/
#include <iostream>
#include <fstream>
#include <stdlib.h>

int main () 
{
    std::ofstream ofs;
    std::ifstream ifs;
    ifs.open("bead.in");
    ofs.open("bead.out");

    std::string numBeads;
    std::string beads;
    
    ifs >> numBeads;
    int N = atoi(numBeads.c_str()); 
    ifs >> beads;
    //std::cout << numBeads << std::endl 
    //          << beads    << std::endl; 
   
    std::string beads3 = beads + beads + beads;
    //std::cout << beads << std::endl; 
    char buffer[350*3+1];
    beads3.copy(buffer, beads3.length(), 0); 
    //std::cout << buffer << std::endl;
    
    //for(int i = 0; i < ...; i++)
    //{
    //
    //} 
    
    return 0;
}
