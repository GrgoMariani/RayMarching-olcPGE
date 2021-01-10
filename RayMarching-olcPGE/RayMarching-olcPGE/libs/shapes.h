#pragma once

#include "vecs.h"

namespace shapes
{
    double sphere(vec p_3d, double radius);
    double udBox(vec p_3d, vec b_3d);
    double udRoundBox(vec p_3d, vec b_3d, double r);
    double sdTorus(vec p_3d, vec t_2d);
    double sdCylinder(vec p_3d, vec c_3d);
    double sdCone(vec p_3d, vec c_2d);
    double sdPlane(vec p_3d, vec n_4d);
    double sdHexPrism(vec p_3d, vec h_2d);
    double sdTriPrism(vec p_3d, vec h_2d);
    double sdCapsule(vec p_3d, vec a_3d, vec b_3d, double r);
    double sdCappedCylinder(vec p_3d, vec h_2d);
    double sdEllipsoid(vec p_3d, vec r_3d);
    double UNION(double d1, double d2);
    double SUBSTRACT(double d1, double d2);
    double INTERSECT(double d1, double d2);
    vec REPEAT(vec p_3d, vec c_3d);
}
