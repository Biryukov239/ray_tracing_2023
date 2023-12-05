#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
  public:
    double e[3];

    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const;
    double y() const;
    double z() const;

    vec3 operator-() const;
    double operator[](int i) const;
    double& operator[](int i);

    vec3& operator+=(const vec3 &v);

    vec3& operator*=(double t);

    vec3& operator/=(double t);

    double length() const;

    double length_squared() const;

using point3 = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v);

inline vec3 operator+(const vec3 &u, const vec3 &v);

inline vec3 operator-(const vec3 &u, const vec3 &v);

inline vec3 operator*(const vec3 &u, const vec3 &v);

inline vec3 operator*(double t, const vec3 &v);

inline vec3 operator*(const vec3 &v, double t);

inline vec3 operator/(vec3 v, double t);

inline double dot(const vec3 &u, const vec3 &v);

inline vec3 cross(const vec3 &u, const vec3 &v);

inline vec3 unit_vector(vec3 v);

#endif
