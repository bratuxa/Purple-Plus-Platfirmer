#include "World.h"
#include <memory>
#include <utility>

World::World(const std::string& WORLD_PLAN) {
    coords.push_back(std::vector<std::shared_ptr<Object>>());
    int currentFloor = 0;
    for(char lookObject: WORLD_PLAN){
        switch (lookObject) {
            
            case ' ' : 
                coords.at(currentFloor).push_back(std::make_shared<Object>());  break;
            case '\n': {
                coords.push_back(std::vector<std::shared_ptr<Object>>()); ++currentFloor;} break;
            case '+': 
                coords.at(currentFloor).push_back(std::make_shared<Player>('+')); break;
            case '-': 
                coords.at(currentFloor).push_back(std::make_shared<Object>('-')); break;
            case '|': 
                coords.at(currentFloor).push_back(std::make_shared<Object>('|')); break;
            default: 
                coords.at(currentFloor).push_back(std::make_shared<Object>());
        };
    }
}

std::ostream& operator<< (std::ostream &OUT, const World &WORLD)
{
    for (auto coordsY : WORLD.coords ) {
        for (auto coordsX : coordsY) {
            OUT << *coordsX;   
        }
        OUT << '\n';
    }
    return OUT;
}       

std::pair<int, int> World::findObject(const char lookObject) const{
    for (int y{0}; y < coords.size(); ++y) {
        for (int x{0}; x < coords.at(y).size(); ++x) {
            if(coords.at(y).at(x)->getLook() == lookObject) return std::pair<int, int> (y,x);
        }
    }

    return std::pair<int, int> (0,0);
}
