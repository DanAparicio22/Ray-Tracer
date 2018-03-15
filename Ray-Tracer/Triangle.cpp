#include "Triangle.h"

Triangle::Triangle() {}

Triangle::Triangle(const Point3D& a, const Point3D& b, const Point3D& c): GeometricObject(), v0(a), v1(b), v2(c)
{
	normal = (v1 - v0) ^ (v2 - v0);
	normal.normalize();
}

Triangle::~Triangle() {}

bool Triangle::impact(const Ray& ray, double& tmin, ShadeRec& sr) const
{
	double a = v0.x - v1.x;
	double b = v0.x - v2.x;
	double c = ray.vecD.x;
	double d = v0.x - ray.O.x;
	double e = v0.y - v1.y;
	double f = v0.y - v2.y;
	double g = ray.vecD.y;
	double h = v0.y - ray.O.y;
	double i = v0.z - v1.z;
	double j = v0.z - v2.z;
	double k = ray.vecD.z;
	double l = v0.z - ray.O.z;

	double m = f * k - g * j;
	double n = h * k - g * l;
	double p = f * l - h * j;
	double q = g * i - e * k;
	double s = e * j - f * i;

	double inv_denom = 1.0 / (a*m + b * q + c * s);

	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_denom;
	if (beta < 0.0)
	{
		return false;
	}

	double r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_denom;
	if (gamma < 0.0)
	{
		return false;
	}

	if (beta + gamma > 1.0)
	{
		return false;
	}

	double e3 = a * p - b * r + d * s;
	double t = e3 * inv_denom;
	if (t < kEpsilon)
	{
		return false;
	}
	tmin = t;
	sr.normal = normal;
	sr.impactLocalPoint = ray.O + ray.vecD*t;
	return true;
}
