#include <iostream>
#include <utility>
#include "MovebleObject.h"

class Player : public MovebleObject{
    
    static int frameNum;
    static const std::vector<char> ANIMATION;
    public:
    static const int JUMP_HEIGHT = 3;
    
    Player(const char LOOK = ' ') : MovebleObject(LOOK){}
    Player(Object& obj) : MovebleObject(obj.getLook()){}

    void nextFrameAnimation(){
        if(frameNum < 0 || frameNum > ANIMATION.size() - 1) frameNum = 0;
        look = ANIMATION[frameNum++];
    };
};