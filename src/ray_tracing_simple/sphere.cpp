#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include "ray.h"

class sphere: public hittable {
  public:
    sphere(point3 center, double radius) : center_(center), radius_(radius) {}

    bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
      Vec3 oc = r.origin() - center_;
      auto a = r.direction().length_squared();
      auto half_b = dot(oc, r.direction());
      auto c = oc.length_squared() - radius_ * radius_;

      auto discriminant = half_b * half_b - a * c;
      if (discriminant < 0) {
        return false;
      }
      auto sqrtd = sqrt(discriminant);

      // Find the nearest root that lies in the acceptable range.
      auto root = (-half_b - sqrtd) / a;
      if (root <= ray_tmin || ray_tmax <= root) {
        root = (-half_b + sqrtd) / a;
        if (root <= ray_tmin || ray_tmax <= root) {
          return false;
        }
      }
      rec.t = root;
      rec.p = r.at(rec.t);
      Vec3 outward_normal = (rec.p - center_) / radius_;
      rec.set_face_normal(r, outward_normal);
      return true;
    }

  private:
    point3 center_;
    double radius_;
};

#endif
