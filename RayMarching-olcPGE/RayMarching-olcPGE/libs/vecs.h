#pragma once

class vec
{
public:
    double _x;
    double _y;
    double _z;
    double _w;
private:
    unsigned short _dim;
public:
    vec(const vec& rvec);
    vec(double x, double y);
    vec(double x, double y, double z);
    vec(double x, double y, double z, double w);

    const unsigned short getDimension();
    double length();

    vec& normalize();
    vec& cross(const vec right);
    vec& clamp_x(double _min, double _max);
    vec& clamp_y(double _min, double _max);
    vec& clamp_z(double _min, double _max);
    vec& clamp_w(double _min, double _max);
    vec& clamp(double _min, double _max);
    vec& vecAbs();
    vec& vecMax(double _max);
    /* Overloaded operators*/
public:
    vec operator+(const vec& right);
    vec operator-(const vec& right);
    vec operator*(const double right);
    vec operator/(const double right);
    double operator^(const vec& right);
    vec operator%(const vec& right);
    vec operator/(const vec& right);
    vec& operator += (const vec& right);
    vec& operator -= (const vec& right);
    vec& operator *= (const double factor);
    vec& operator /= (const double factor);
    /* Reflections and such */
public:
    vec& convertTo2D();
    vec& convertTo3D();
    vec& convertTo4D();
    vec& projectToPlaneXY();
    vec& projectToPlaneXZ();
    vec& projectToPlaneYZ();
    vec& projectToVector(vec& _vec);
    vec& switchXY();
    vec& switchXZ();
    vec& switchYZ();
};
