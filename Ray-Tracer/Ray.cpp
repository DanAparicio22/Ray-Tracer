#include "Ray.h"

Ray::Ray() : p(0.0), v(0.0, 0.0, 1.0) {}

Ray::~Ray() {}

Ray::Ray(const Point3D & o, const Vector3D & d) : p(o), v(d) {}

Ray::Ray(const Ray &r) : p(r.p), v(r.v) {}

Ray & Ray::operator=(const Ray &rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	p = rhs.p;
	v = rhs.v;
	return (*this);
}