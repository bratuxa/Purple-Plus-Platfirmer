
#include <iostream>
#include <utility>
#include <vector>

class Object{
    protected:
    char look;
    
    public:
        Object(const char LOOK = ' ') : look(LOOK){};
        friend std::ostream& operator<< (std::ostream &OUT, const Object OBJECT);
        virtual char getLook(){ return look; }
        
};

class MovebleObject : public Object{
    protected:
    int x, y;
    public:
    MovebleObject(const char LOOK = ' ', const int Y = 0, const int X = 0) : Object(LOOK), y(Y),x(X){}
    MovebleObject(Object& obj) : Object(obj.getLook()){}
    virtual inline void setObject(const int Y, const int X){y = Y, x = X;}
    virtual inline void setObject(const std::pair<int, int>& PAIR){y = PAIR.first, x = PAIR.second;}
};

