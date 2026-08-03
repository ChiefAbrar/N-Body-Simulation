#ifndef BODY_HPP
#define BODY_HPP

#include "vector.hpp"

struct Body {
    Vector pos;
    Vector vel;
    Vector acc;
    double mass = 1.0;
    int id = -1;
};
#endif