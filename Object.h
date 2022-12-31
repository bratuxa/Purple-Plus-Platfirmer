
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

