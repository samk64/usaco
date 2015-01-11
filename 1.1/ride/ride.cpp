/*
ID: samk641
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

int ASCII_OFFSET = 64;

//using namespace std;
int calculateNum(std::string name){
    int num = 0;
    for(int i=0; i < name.length(); ++i){
        if(i==0){
            num = (int)name[i] - ASCII_OFFSET;
        }
        else{
            num *= ((int)name[i] - ASCII_OFFSET);
        }
    }
    return num;
}

int main() {            
    
    std::ofstream fout ("ride.out");
    std::ifstream fin ("ride.in");
    std::string group = "";
    std::string comet = "";
    fin >> comet >> group;

    int MODULUS = 47;
    
    int cometNum = calculateNum(comet);
    int groupNum = calculateNum(group);

    if(groupNum % MODULUS == cometNum % MODULUS){
        fout << "GO" << std::endl;
        printf("GO");
    }
    else{
        fout << "STAY" << std::endl;
        printf("STAY");
    }
    
    return 0;
}

//COMETQ
//HVNGAT
// GO

// ABSTAR
// USACO
// STAY