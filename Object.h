
#include <iostream>

class Object{
    
    int x, y;
    char look;
    bool isCollision;

    public:
        Object(const char LOOK = ' ',const bool IS_COLLISION = false);
        friend std::ostream& operator<< (std::ostream &OUT, const Object OBJECT);
};
