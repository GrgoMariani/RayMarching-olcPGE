#pragma once

#include "vecs.h"


namespace e_glsl
{
    double clamp(double value, double _min, double _max);
    vec reflect(vec I, vec N);
    vec normalize(vec I);
    vec cross(vec A, vec B);
}

