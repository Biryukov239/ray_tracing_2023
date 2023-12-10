#ifndef Vec3_H
#define Vec3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class Vec3 {
  private:
    double x_;
    double y_;
    double z_;
  public:
    Vec3();
    Vec3(double x, double y, double z);

    double x() const;
    double y() const;
    double z() const;

    Vec3 operator-() const;
    double operator[](int ind) const;
    double& operator[](int ind);

    Vec3& operator+=(const Vec3& vec);

    Vec3& operator*=(double value);

    Vec3& operator/=(double value);

    double length() const;

    double length_squared() const;
};

using point3 = Vec3;

std::ostream& operator<<(std::ostream& out, const Vec3& vec);

Vec3 operator+(const Vec3& vec1, const Vec3& vec2);

Vec3 operator-(const Vec3& vec1, const Vec3& vec2);

Vec3 operator*(const Vec3& vec1, const Vec3& vec2);

Vec3 operator*(double value, const Vec3& vec);

Vec3 operator/(const Vec3& vec, double value);

double dot(const Vec3& vec1, const Vec3& vec2);

Vec3 cross(const Vec3& vec1, const Vec3& vec2);

Vec3 unit_vector(const Vec3& vec);

#endif
