#include <iostream>
#include <utility>
#include "Object.h"

class Player : public Object{
    
    int x, y;
    static int frameNum;
    static const std::vector<char> ANIMATION;
    public:
    static const int JUMP_HEIGHT = 3;
    
    Player(const char LOOK = ' ') : Object(LOOK), x(0),y(0){}

    inline std::pair<int, int> getPlayer(){ return std::pair<int, int>(y,x);}
    void nextFrameAnimation(){
        if(frameNum < 0 || frameNum > ANIMATION.size() - 1) frameNum = 0;
        look = ANIMATION[frameNum++];
    };
    inline void setPlayer(const int Y, const int X){y = Y, x = X;}
    inline void setPlayer(const std::pair<int, int>& PAIR){y = PAIR.first, x = PAIR.second;}
};