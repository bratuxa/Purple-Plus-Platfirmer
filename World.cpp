#include "World.h"
#include <memory>

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
                coords.at(currentFloor).push_back(std::make_shared<Object>('+',true)); break;
            case '-': 
                coords.at(currentFloor).push_back(std::make_shared<Object>('-', true)); break;
            case '|': 
                coords.at(currentFloor).push_back(std::make_shared<Object>('|', true)); break;
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
