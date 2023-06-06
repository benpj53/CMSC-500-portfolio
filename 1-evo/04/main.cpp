#include <iostream>
#include "BitsPop.h"

int main() {

    int popsize = 1000;
    int genomesize = 100;
    int n_generations = 100;

    BitsPop population(popsize, genomesize);;

    int current_generation = 1;

    for (int i = 0; i < n_generations; i++) {

        std::cout << "Current generation: " << current_generation << std::endl;

        // Selection
        std::vector<BitsOrganism*> newpop;
        //int k = 7; // tournament size
        //newpop = population.tournament_select(k);
        newpop = population.roulette_select(); 
        //newpop = population.getPop(); // currently there's no selection, so remove this when you add selection!

        // variation
        for (auto org : population.getPop()) {
            org->point_mutate();
            //org.genome.block_mutate(k);
        }

        // heritability
        population.update(newpop);

        double total_fitness = 0;
        double max_fitness = 0;
        double number_of_organisms = 0; 

        for (BitsOrganism* org : newpop) {

            if(max_fitness <= org->getScore()){

                max_fitness = org->getScore();

            }

            total_fitness = total_fitness + org->getScore(); 

            number_of_organisms = number_of_organisms + 1;
        }  

        double mean_fitness = total_fitness / number_of_organisms;    

        std::cout<< "Gen: " << current_generation << "\t MAX: " << max_fitness << "\t MEAN: " << mean_fitness << std::endl; 

        current_generation = current_generation + 1;

        std::cout << std::endl;


    }

}