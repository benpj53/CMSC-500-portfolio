/*Create a C++ class called Organism
    - Integer: age
    - String: name
    - boolean: isAlive
    - Constructors

    - Operator override 
        - to compare by age (compare 2 organisms, tell whether one is bigger or smaller by age)


Population
    - Vector of Organisms - popvec
    - Make a population of 20 organisms w/random age
    - Sort the vector using std::sort
*/

#include <stdio.h>
#include <stdlib.h> 
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Organism {

    public: 
        int age; 
        string name; 
        bool isAlive; 
    
    bool operator < (Organism org) {
        if(org.age > age){
            return true;
        } else {
            return false;
        }
    }

    Organism(){
        age = 0;
        name = "unnamed";
        isAlive = false;
    }

    ~Organism(){}; //Destructor

};

class Population {

    public: 
        vector<Organism> popvec;
 
    Population(){
        for(int i=0; i<20; i++){
            Organism newOrganism;
            newOrganism.age = rand();
            newOrganism.isAlive = true;

            popvec.push_back(newOrganism);    
        }

        sort(popvec.begin(), popvec.end());
        for (vector<Organism>::iterator it=popvec.begin(); it!=popvec.end(); ++it)
            {//std::cout << ' ' *it;
            }
    }

};

