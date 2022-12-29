#include "Object.h"

Object::Object(const char LOOK, const bool IS_COLLISION) : look(LOOK), isCollision(IS_COLLISION){}

std::ostream& operator<< (std::ostream &OUT, const Object OBJECT)
{
    OUT << OBJECT.look;
    return OUT;
}      