
#include <utility>
#include <vector>
#include <memory>
#include "Player.h"

class World{
    private:
        std::vector<std::vector<std::shared_ptr<Object>>> coords;
        std::vector<std::pair<std::shared_ptr<MovebleObject>, char>> objectsMoveble;
    public: 
        World(const std::string& WORLD_PLAN);
        std::vector<std::pair<std::shared_ptr<MovebleObject>, char>>& getObjectsMoveble(){ return objectsMoveble; }
        std::pair<int, int> findObject(const char lookObject) const;
        std::shared_ptr<Object>& getObjectPtr(const std::pair<int,int> &PAIR){ return coords.at(PAIR.first).at(PAIR.second); }
        std::shared_ptr<Object>& getObjectPtr(const int y, const int x){ return coords.at(y).at(x); }
        Object& getObject(const int y, const int x){ return *getObjectPtr(y,x); }
        friend std::ostream& operator<< (std::ostream &OUT, const World &WORLD);
};