
#include <iostream>
#include <vector>
#include <memory>
#include "Object.h"

class World{
    private:
        std::vector<std::vector<std::shared_ptr<Object>>> coords;
    public: 
        World(const std::string& WORLD_PLAN);
    
    friend std::ostream& operator<< (std::ostream &OUT, const World &WORLD);
};