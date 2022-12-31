#include <iostream>
#include <utility>

class Player{
    int x, y;

    public:
    static const int JUMP_HEIGHT = 3;

    Player(const int Y = 0, const int X = 0);

    inline std::pair<int, int> getPlayer(){ return std::pair<int, int>(y,x);}
    inline void setPlayer(const int Y, const int X){y = Y, x = X;}
};