#include "Object.h"

std::ostream& operator<< (std::ostream &OUT, const Object OBJECT)
{
    OUT << OBJECT.look;
    return OUT;
}      

