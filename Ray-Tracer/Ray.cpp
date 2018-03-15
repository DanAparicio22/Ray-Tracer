#include"Ray.h"

Ray::Ray() : O(0.0), vecD(0.0, 0.0, 1.0) {}

Ray::Ray(const Point3D& origin, const Vector3D& direction) : O(origin), vecD(direction) {}

Ray::Ray(const Ray& r) : O(r.O), vecD(r.vecD) {}

Ray::~Ray() {}

Ray& Ray::operator=(const Ray& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	O = rhs.O;
	vecD = rhs.vecD;
	return (*this);
}