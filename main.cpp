#include <iostream>
#include <vector>
#include <memory>
#include "World.h"


int main(int, char**) {
    World world = World(
    "|             |\n" 
               "|+            |\n"
                "|-------------|");

    std::cout << world;
}
