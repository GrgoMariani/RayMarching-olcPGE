#include <cmath>
#include "libs/vecs.h"

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


vec::vec(const vec& rvec) : _x(rvec._x), _y(rvec._y), _z(rvec._z), _w(rvec._w), _dim(rvec._dim)
{

}

vec::vec(double x, double y) : _x(x), _y(y), _z(0), _w(0), _dim(2)
{

}

vec::vec(double x, double y, double z) : _x(x), _y(y), _z(z), _w(0), _dim(3)
{

}

vec::vec(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w), _dim(4)
{

}

const unsigned short vec::getDimension()
{
    return this->_dim;
}

double vec::length()
{
    return sqrt(this->_x * this->_x + this->_y * this->_y + this->_z * this->_z + this->_w * this->_w);
}

vec& vec::normalize()
{
    // could use a fast inverse sqrt here instead, but this is not a lecture in optimization
    double dist = this->length();
    if (dist != 0)
    {
        this->_x /= dist;
        this->_y /= dist;
        this->_z /= dist;
        this->_w /= dist;
    }
    return *this;
}
vec& vec::cross(const vec right)
{
    //only vec3-s for now
    double _x = this->_y * right._z - this->_z * right._y;
    double _y = -this->_x * right._z + this->_z * right._x;
    double _z = this->_x * right._y - this->_y * right._x;
    this->_x = _x, this->_y = _y, this->_z = _z, this->_dim = 3;
    return *this;
}

vec& vec::clamp_x(double _min, double _max)
{
    this->_x = min(max(this->_x, _min), _max);
    return *this;
}

vec& vec::clamp_y(double _min, double _max)
{
    this->_y = min(max(this->_y, _min), _max);
    return *this;
}

vec& vec::clamp_z(double _min, double _max)
{
    this->_z = min(max(this->_z, _min), _max);
    return *this;
}

vec& vec::clamp_w(double _min, double _max)
{
    this->_w = min(max(this->_w, _min), _max);
    return *this;
}

vec& vec::clamp(double _min, double _max)
{
    this->clamp_x(_min, _max);
    this->clamp_y(_min, _max);
    if (this->_dim > 2) this->clamp_z(_min, _max);
    if (this->_dim > 3) this->clamp_w(_min, _max);
    return *this;
}

vec& vec::vecAbs()
{
    this->_x = abs(this->_x);
    this->_y = abs(this->_y);
    this->_z = abs(this->_z);
    this->_w = abs(this->_w);
    return *this;
}

vec& vec::vecMax(double _max)
{
    this->_x = max(_max, this->_x);
    this->_y = max(_max, this->_y);
    this->_z = max(_max, this->_z);
    this->_w = max(_max, this->_w);
    return *this;
}

vec vec::operator+(const vec& right)
{
    return vec(this->_x + right._x, this->_y + right._y, this->_z + right._z, this->_w + right._w);
}

vec vec::operator-(const vec& right)
{
    return vec(this->_x - right._x, this->_y - right._y, this->_z - right._z, this->_w - right._w);
}

vec vec::operator*(const double right)
{
    return vec(this->_x * right, this->_y * right, this->_z * right, this->_w * right);
}

vec vec::operator/(const double right)
{
    return vec(this->_x / right, this->_y / right, this->_z / right, this->_w / right);
}

double vec::operator^(const vec& right)
{  // DOT PRODUCT
    return this->_x * right._x + this->_y * right._y + this->_z * right._z + this->_w * right._w;
}

vec vec::operator%(const vec& right)
{  // modulo - only vec3
    /** Is this it ? */
    vec result(*this);
    vec y(right);
    double _ratio = floor(result.length() / y.length());
    int _sign = ((result ^ y) > 0) ? 1 : -1;
    if (y.length())
    {
        result -= y * (_ratio * _sign);
    }
    return result;
}

vec vec::operator/(const vec& right)
{
    double result_x = (right._x) ? this->_x / right._x : 1.0;
    double result_y = (right._y) ? this->_y / right._y : 1.0;
    double result_z = (right._z) ? this->_z / right._z : 1.0;
    double result_w = (right._w) ? this->_w / right._w : 1.0;
    return vec(result_x, result_y, result_z, result_w);
}

vec& vec::operator += (const vec& right)
{
    this->_x += right._x;
    this->_y += right._y;
    this->_z += right._z;
    this->_w += right._w;
    return *this;
}

vec& vec::operator -= (const vec& right)
{
    this->_x -= right._x;
    this->_y -= right._y;
    this->_z -= right._z;
    this->_w -= right._w;
    return *this;
}

vec& vec::operator *= (const double factor)
{
    this->_x *= factor;
    this->_y *= factor;
    this->_z *= factor;
    this->_w *= factor;
    return *this;
}

vec& vec::operator /= (const double factor)
{
    this->_x /= factor;
    this->_y /= factor;
    this->_z /= factor;
    this->_w /= factor;
    return *this;
}

/* Reflections and such */
vec& vec::convertTo2D()
{
    this->_z = 0, this->_w = 0, this->_dim = 2;
    return *this;
}

vec& vec::convertTo3D()
{
    this->_w = 0, this->_dim = 3;
    return *this;
}

vec& vec::convertTo4D()
{
    this->_dim = 4;
    return *this;
}

vec& vec::projectToPlaneXY()
{
    this->_z = 0;
    return *this;
}

vec& vec::projectToPlaneXZ()
{
    this->_y = 0;
    return *this;
}

vec& vec::projectToPlaneYZ()
{
    this->_x = 0;
    return *this;
}

vec& vec::projectToVector(vec& _vec)
{
    double factor = (this->operator^(_vec)) / (_vec ^ _vec);
    this->operator*=(factor);
    return *this;
}

vec& vec::switchXY()
{
    double temp = this->_x;
    this->_x = this->_y;
    this->_y = temp;
    return *this;
}

vec& vec::switchXZ()
{
    double temp = this->_x;
    this->_x = this->_z;
    this->_z = temp;
    return *this;
}

vec& vec::switchYZ()
{
    double temp = this->_z;
    this->_z = this->_y;
    this->_y = temp;
    return *this;
}




// GLSL_EMULATED.h related
#include "libs/glsl_emulated.h"

namespace e_glsl {

    double clamp(double value, double _min, double _max)
    {
        return min(max(value, _min), _max);
    }

    vec reflect(vec I, vec N)
    {
        return I - (N * (N ^ I) * 2.0);
    }

    vec normalize(vec I)
    {
        double dist = I.length();
        vec result(I);
        if (dist != 0) result /= dist;
        return result;
    }

    vec cross(vec A, vec B)
    {
        //only vec3-s for now
        double _x = A._y * B._z - A._z * B._y;
        double _y = -A._x * B._z + A._z * B._x;
        double _z = A._x * B._y - A._y * B._x;
        return vec(_x, _y, _z);
    }
}


// SHAPES.h related
#include "libs/shapes.h"
namespace shapes
{
    double sphere(vec p_3d, double radius)
    {
        return p_3d.length() - radius;
    }

    double udBox(vec p_3d, vec b_3d)
    {
        return (p_3d.vecAbs() - b_3d).vecMax(0.0).length();
    }

    double udRoundBox(vec p_3d, vec b_3d, double r)
    {
        return udBox(p_3d, b_3d) - r;
    }

    double sdTorus(vec p_3d, vec t_2d)
    {
        vec q_2d = vec(p_3d.projectToPlaneXZ().length() - t_2d._x, p_3d._y);
        return q_2d.length() - t_2d._y;
    }

    double sdCylinder(vec p_3d, vec c_3d)
    {
        return (p_3d.projectToPlaneXZ().switchYZ() - c_3d.projectToPlaneXY()).length() - c_3d._z;
    }

    double sdCone(vec p_3d, vec c_2d)
    {
        c_2d.normalize();
        double q = p_3d.projectToPlaneXY().length();
        return c_2d ^ vec(q, p_3d._z);
    }

    double sdPlane(vec p_3d, vec n_4d)
    {
        n_4d.normalize();
        return (p_3d ^ n_4d) + n_4d._w;
    }

    double sdHexPrism(vec p_3d, vec h_2d)
    {
        vec q_3d = p_3d.vecAbs();
        return max(q_3d._z - h_2d._y, max((q_3d._x * 0.866025 + q_3d._y * 0.5), q_3d._y) - h_2d._x);
    }

    double sdTriPrism(vec p_3d, vec h_2d)
    {
        vec q = p_3d.vecAbs();
        return max(q._z - h_2d._y, max(q._x * 0.866025 + p_3d._y * 0.5, -p_3d._y) - h_2d._x * 0.5);
    }

    double sdCapsule(vec p_3d, vec a_3d, vec b_3d, double r)
    {
        vec pa_3d = p_3d - a_3d, ba_3d = b_3d - a_3d;
        double h = e_glsl::clamp((pa_3d ^ ba_3d) / (ba_3d ^ ba_3d), 0.0, 1.0);
        return (pa_3d - ba_3d * h).length() - r;
    }

    double sdCappedCylinder(vec p_3d, vec h_2d)
    {
        vec d_2d = vec(p_3d.projectToPlaneXZ().length(), p_3d._y).vecAbs() - h_2d;
        return min(max(d_2d._x, d_2d._y), 0.0) + d_2d.vecMax(0.0).length();
    }

    double sdEllipsoid(vec p_3d, vec r_3d)
    {
        return ((p_3d / r_3d).length() - 1.0) * min(min(r_3d._x, r_3d._y), r_3d._z);
    }

    double UNION(double d1, double d2)
    {
        return min(d1, d2);
    }

    double SUBSTRACT(double d1, double d2)
    {
        return max(-d1, d2);
    }

    double INTERSECT(double d1, double d2)
    {
        return max(d1, d2);
    }

    vec REPEAT(vec p_3d, vec c_3d)
    {
        // usage:  sphere(REPEAT(p_3d), 5)
        vec q_3d = (p_3d % c_3d) - (c_3d / 2.0);
        return q_3d;
    }


    // Shapes added from
    // http://iquilezles.org/www/articles/distfunctions/distfunctions.htm


}
