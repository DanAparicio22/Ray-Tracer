#include "Sphere.h"

Sphere::Sphere() : GeometricObject(), C(0.0), r(1.0) {}
Sphere::Sphere(Point3D _c, double _r) : GeometricObject(), C(_c), r(_r) {}
Sphere::Sphere(const Sphere& _e) : GeometricObject(_e), C(_e.C), r(_e.r) {}
Sphere::~Sphere() {}

Sphere& Sphere::operator= (const Sphere& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	GeometricObject::operator=(rhs);
	C = rhs.C;
	r = rhs.r;
	return (*this);
}
void Sphere::stablishCenter(const Point3D& _p)
{
	C = _p;
}
void Sphere::stablishCenter(const double _x, const double _y, const double _z)
{
	C.x = _x;
	C.y = _y;
	C.z = _z;
}
void Sphere::stablishRadius(const double _r)
{
	r = _r;
}

bool Sphere::impact(const Ray& ray, double& tmin, ShadeRec& sr) const
{
	double t;
	Vector3D temp = ray.p - C;
	double a = ray.v * ray.v;
	double b = 2 * (ray.v * (ray.p - C));
	double c = (ray.p - C)*(ray.p - C) - (r * r);
	double discriminate = b * b - 4 * a*c;
	if (discriminate < 0)
	{
		return false;
	}
	else
	{
		double e = sqrt(discriminate);
		double denom = 2.0 * a;
		t = (-b - e) / denom;
		if (t > kEpsilon)
		{
			tmin = t;
			sr.normal = (temp + (ray.v * t)) / r;
			sr.impactLocalPoint = ray.p + ray.v * t;
			return true;
		}
		t = (-b + e) / denom;

		if (t > kEpsilon)
		{
			tmin = t;
			sr.normal = (temp + (ray.v * t)) / r;
			sr.impactLocalPoint = ray.p + ray.v * t;
			return true;
		}
	}
	return false;
}


