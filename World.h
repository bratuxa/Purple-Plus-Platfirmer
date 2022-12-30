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
        std::shared_ptr<Object> getObjectPtr (const int y, const int x){
            return coords.at(y).at(x);
        };
        std::pair<int, int> findObject(const char charObject);
    
};