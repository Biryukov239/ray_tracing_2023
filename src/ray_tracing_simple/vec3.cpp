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
    Vec3(): x_(0), y_(0), z_(0) {}

    Vec3(double x, double y, double z): x_(x), y_(y), z_(z) {}

    double x() const {
      return x_;
    }


    double y() const {
      return y_;
    }


    double z() const {
      return z_;
    }


    Vec3 operator-() const {
      return Vec3(-x_, -y_, -z_);
    }


    double operator[](int i) const {
      if (i == 0) {
        return x_;
      }
      if (i == 1) {
        return y_;
      }
      if (i == 2) {
        return z_;
      }
      return -1'000'000;
    }


    Vec3& operator+=(const Vec3& vec) {
        x_ += vec.x();
        y_ += vec.y();
        z_ += vec.z();
        return *this;
    }


    Vec3& operator*=(double value) {
        x_ *= value;
        y_ *= value;
        z_ *= value;
        return *this;
    }


    Vec3& operator/=(double value) {
        return *this *= 1 / value;
    }


    double length() const {
        return sqrt(square_diagonal());
    }


    double square_diagonal() const {
        return x_ * x_ + y_ * y_ + z_ * z_;
    }
};

// point3 is just an alias for Vec3, but useful for geometric clarity in the code.
using point3 = Vec3;

std::ostream& operator<<(std::ostream &out, const Vec3& vec) {
    return out << vec.x() << ' ' << vec.y() << ' ' << vec.z();
}


Vec3 operator+(const Vec3& vec1, const Vec3& vec2) {
    return Vec3(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
}


Vec3 operator-(const Vec3& vec1, const Vec3& vec2) {
    return vec1 + (-vec2);
}


Vec3 operator*(const Vec3& vec1, const Vec3& vec2) {
    return Vec3(vec1.x() * vec2.y(), vec1.y() * vec2.y(), vec1.z() * vec2.z());
}


Vec3 operator*(double value, const Vec3& vec) {
    return Vec3(value * vec.x(), value * vec.y(), value * vec.z());
}


Vec3 operator/(const Vec3& vec, double t) {
    return (1 / t) * vec;
}


double dot(const Vec3& vec1, const Vec3& vec2) {
    return vec1.x() * vec2.x() + vec1.y() * vec2.y()+ vec1.z() * vec2.z();
}


Vec3 cross(const Vec3& vec1, const Vec3& vec2) {
    return Vec3(vec1.y() * vec2.z() - vec1.z() * vec2.y(),
                vec2.z() * vec1.x() - vec2.x() * vec2.z(),
                vec1.x() * vec2.y() - vec1.y() * vec2.x());
}


Vec3 unit_vector(const Vec3& vec) {
    return vec / vec.length();
}

#endif
