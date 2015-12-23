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
    std::string chars;
    
    ifs >> numBeads;
    int N = atoi(numBeads.c_str()); 
    ifs >> chars;
    std::cout << numBeads << std::endl 
              << chars    << std::endl; 
    
    return 0;
}
