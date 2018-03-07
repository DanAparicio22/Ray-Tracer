#include "Triangle.h"

Triangle::Triangle() : v0(-40.0,-40.0,-100.0), v1(60.0,-30.0,-100.0), v2(60.0,60.0,-90.0) 
{
	normal = (v1 - v0)*(v2 - v0);
	normal.normalize();
}

Triangle::Triangle(Point3D& p0, Point3D& p1, Point3D& p2) : v0(p0), v1(p1), v2(p2) {}

Triangle::Triangle(const Triangle & t): v0(t.v0), v1(t.v1), v2(t.v2) { }

Triangle::~Triangle()
{
}

void Triangle::stablishPoints(const Point3D & p1, const Point3D & p2, const Point3D &p3)
{
	v0 = p1;
	v1 = p2;
	v2 = p3;
}

bool Triangle::impact(const Ray &ray, double &tmin, ShadeRec &sr) const
{
	double a = v0.x - v1.x;
	double b = v0.x - v2.x;
	double c = ray.v.x;
	double d = v0.x - ray.p.x;
	double e = v0.y - v1.y;
	double f = v0.y - v2.y;
	double g = ray.v.y;
	double h = v0.y - ray.p.y;
	double i = v0.z - v1.z;
	double j = v0.z - v2.z;
	double k = ray.v.z;
	double l = v0.z - ray.p.z;
	double m = f * k - g * j;
	double n = h * k - g * l;
	double p = f * l - h * j;
	double q = g * i - e * k;
	double s = e * j - f * l;
	double inv_denom = 1.0 / (a*m + b * q + c * s);
	double e1 = d * m - b * n - c * p;
	double beta = e1 * inv_denom;
	if (beta < 0.0) 
	{
		return false;
	}
	//gamma
	double r = e * l - h * i;
	double e2 = a * n + d * q + c * r;
	double gamma = e2 * inv_denom;
	if (gamma < 0.0)
	{
		return false;
	}
	if (beta+gamma > 1.0) 
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
	sr.impactLocalPoint = ray.p + ray.v*t;
	return true;
}

Triangle & Triangle::operator=(const Triangle &tri)
{
	if (this == &tri)
	{
		return (*this);
	}
	GeometricObject::operator=(tri);
	v0 = tri.v0;
	v1 = tri.v1;
	v2 = tri.v2;
	return (*this);
}
