#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

class hittable_list: public hittable {
  public:
    std::vector<hittable> objects;

    hittable_list();
    hittable_list(hittable object);

    void clear();

    void add(hittable object);

    bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
};

#endif
