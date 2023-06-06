#include <iostream>
#include "BitsPop.h"

int main() {
    BitsPop pop(100, 10);

    for (int i = 0; i < 100; i++) {
        std::cout << pop.getPop()[i]->getScore() << std::endl;
    }
}