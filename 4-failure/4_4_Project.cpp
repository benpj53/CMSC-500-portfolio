#include <stdio.h>
#include <stdlib.h> 
#include <iostream>

using namespace std;

class organismData {

    private: 
        string dna; 
        string mrna[10];
        string polypeptide;

    organismData(){
        //Generate random DNA sample from "TAGC"

    }

    void transcription(string dna){
        //Group the DNA for each 3 letter
        //Set each DNA group as the mrna

    }

    void translation(){
        //Iterate through mRNA array

    }

};

#include <vector>
template<class T>
class AbstractGenome {

    protected:
        std::vector<T> genome;
    
    public:
        AbstractGenome(int n){
            genome.resize(n);
        }
        ~AbstractGenome(){};

        void fill(T x) {
            std::fill(genome.begin(), genome.end(), x);
        }
        std::vector<T> get() {
            return genome;
        }

        void set(std::vector<T> x){
            genome = x;
        }
};

#include <algorithm>
class BitsGenome: public AbstractGenome<bool> {

    int ones(){
        return std::count(genome.begin(), genome.end(), 1);
    }

};

