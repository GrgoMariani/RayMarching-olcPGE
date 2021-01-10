#pragma once
     
extern const int MAX_STEPS;
extern const double MAX_DISTANCE;
extern const double EPSILON;

class vec;

extern const vec resolution_2d;
extern double _ratio;


vec renderXY(vec gl_FragCoord_2d);
