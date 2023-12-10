#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
  public:
    point3 p;
    Vec3 normal;
    double t;

    void set_face_normal(const Ray& r, const Vec3& outward_normal);
};

class hittable {
  public:
    virtual ~hittable();

    virtual bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const;
};

#endif
