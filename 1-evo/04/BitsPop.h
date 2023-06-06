#ifndef BITSPOP_H_
#define BITSPOP_H_

#include <iostream>
#include "BitsOrganism.h"

class BitsPop {

    std::vector<BitsOrganism *> pop;
    int popsize;

public:

    BitsPop(int n, int genomesize) {
        popsize = n;
        for (int i = 0; i < n; i++) {
            BitsOrganism* org = new BitsOrganism(genomesize);
            pop.push_back(org);
        }
    }

    void update(const std::vector<BitsOrganism*> & newpop) {
        pop = newpop;
    }

    std::vector<BitsOrganism*> getPop() {
        return pop;
    }

    BitsOrganism* getMax() {
        auto it = std::max_element(pop.begin(), pop.end());
        return *it;
    }

    std::vector<BitsOrganism*> tournament_select(int tournsize) {
        //Create new population
        std::vector<BitsOrganism*> newPop;

        //Setup tournament loop -----
        while( pop.size() != newPop.size() ) {

            //Fill up tournament party
            std::vector<BitsOrganism *> tournamentParty;
            for(int i = 0; i<tournsize; i++) {
                int organismChoice = rand() % pop.size(); 
                tournamentParty.push_back(pop[organismChoice]);
            }

            //*Worldstar*
            BitsOrganism* winningOrganism = tournamentParty[1];
            for(BitsOrganism* organism : tournamentParty) {
                if( winningOrganism->getScore() < organism->getScore() ) {
                    winningOrganism = organism;
                }
            }

            newPop.push_back(winningOrganism);
        }

        //Return new population
        return newPop;
    }

    std::vector<BitsOrganism*> roulette_select() {
        //Create roulette wheel
        std::vector<BitsOrganism*> rouletteWheel;

        //Get the total fitness of the population, and load each organism into the rouletteWheel, organized by fitness
        int totalFitness = 0; 
        for(BitsOrganism* organism : pop){
            totalFitness = totalFitness + organism->getScore(); 
            int organismScore = organism->getScore();
            //Adding a new organism into the roulette wheel as many times as its fitness, creating the wheel
            for (int i = 0; i < organismScore; i++) { 
                rouletteWheel.push_back(organism);
            }
        }

        std::cout << "Roulette wheel has been filled, it's size is: " << rouletteWheel.size() << std::endl; 

        //Create new population
        std::vector<BitsOrganism*> newPop;

        //--LOOP-- until new population size == this.pop size
        while( pop.size() != newPop.size() ){
            
            int fitnessChoice = rand() % totalFitness;

            newPop.push_back(rouletteWheel[fitnessChoice]);

        }

        std::cout << "New population has been filled, it's size is: " << newPop.size() << std::endl;

        rouletteWheel.clear();

        //return new population
        return newPop;


    }

};

#endif /*BITSPOP_H_*/