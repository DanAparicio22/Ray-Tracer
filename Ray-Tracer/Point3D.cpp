#include "Point3D.h"

Point3D::Point3D() : x(0.0), y(0.0), z(0.0) {}

Point3D::~Point3D() {}

Point3D::Point3D(double a) : x(a), y(a), z(a) {}

Point3D::Point3D(double a, double b, double c) : x(a), y(b), z(c) {}

Point3D::Point3D(const Point3D & p) : x(p.x), y(p.y), z(p.z) {}

Point3D& Point3D::operator=(const Point3D & rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Vector3D Point3D::operator-(Point3D p) const
{
	return Vector3D(x-p.x,y-p.y,z-p.z);
}

Point3D Point3D::operator+(Vector3D p) const
{
	return Point3D(x + p.x, y+p.y, z+p.z);
}
