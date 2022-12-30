
#include <iostream>

class Object{
    
    char look;
    bool isCollision;

    public:
        Object(const char LOOK = ' ',const bool IS_COLLISION = false);
        friend std::ostream& operator<< (std::ostream &OUT, const Object OBJECT);
        char getLook() const { return look; }
};
