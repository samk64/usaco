/*
ID: samk641
PROG: gift1
LANG: C++
*/


#include <fstream>
#include <iostream>
#include <string>   // string
#include <stdlib.h> // atoi
#include <map>      // map
#include <assert.h> // assert
#include <list>
// forward declarations
void splitStringToNumbers(std::string line, int &n1, int &n2);

// output : net gain or loss
// person's profit: (final_money_value - initial_money_value)
// profit = giving - getting

int main(){
    std::map<std::string, int> mapNames = std::map<std::string, int>();
    std::ifstream fin("gift1.in");
    std::ofstream fout("gift1.out");
    std::string line = "";
    std::list<std::string> listNames = std::list<std::string>();

    // read a line
    int lineNo = 1;
    int numPeople = 0;

    // inner loop variables
    std::string giver = "";
    int amt = -1;
    int numRecipients = -1;
    int recipientCounter = -1;
    // remainder

    while( ! fin.eof() ){

        // line 1: N number of people
        if(lineNo == 1){
            std::getline(fin, line);
            numPeople = atoi(line.c_str());
        }

        // lines 2 to N+1: names of people
        else if (lineNo <= numPeople+1 ){
            std::getline(fin, line);

            // save name, initialize
            mapNames[line] = 0;
            listNames.push_back(line);
            // std::cout << line << std::endl;
        }
        // rest: people and their gift amounts, and recipients
        else{
            std::getline(fin, line);

            // get name
            if(giver == ""){
                giver = line;
                //std::cout<<giver<<std::endl;

            }
            // get amount + number recipients
            else if(amt == -1){
                recipientCounter = 0;
                // std::cout << "split numbers" << std::endl;
                splitStringToNumbers(line, amt, numRecipients);

                // add remainder to self
                if(numRecipients != 0){
                    mapNames[giver] -= amt;
                    mapNames[giver] += (amt % numRecipients);
                } else if(numRecipients == 0){
                    mapNames[giver] += amt;
                    giver = ""; // reset
                    amt = -1;
                }

                // std::cout << amt << std::endl;std::cout << amt << std::endl;
                // std::cout << numRecipients << std::endl;
            }
            // get recipient names
            else {

                // give money to recipients
                if(numRecipients != 0){
                    mapNames[line] += (int)(amt / numRecipients);
                }

                //std::cout << line << std::endl;
                //if(numRecipients > 0){
                recipientCounter += 1;
                //}

                // reset
                if(recipientCounter >= numRecipients){
                    giver = "";
                    amt = -1;
                    //recipientCounter = 0;
                }
            }
        }
        lineNo++;
    }

    //printf("Lines: %d\n", lineNo-2);

    for(std::list<std::string>::iterator it = listNames.begin(); it != listNames.end(); ++it){
        fout << *it << " " << mapNames[*it] << std::endl;
        // std::cout << *it << std::endl;
    }

    //printf("%d", listNames.size());

    fin.close();

    return 0;
}

// string with two numbers --> two ints
void splitStringToNumbers(std::string line, int &n1, int &n2){
    std::size_t idx = line.find(' ');

    //std::cout << line << std::endl;
    assert(idx != std::string::npos);
    n1 = atoi( line.substr(0, idx).c_str() );
    n2 = atoi( line.substr(idx+1).c_str() );

    // std::cout   << "two numbers: "
    //             <<  n1 << " and "
    //             <<  n2 << std::endl;

}