#include "Point3D.h"

Point3D::Point3D() 
{
	x = 0;
	y = 0;
	z = 0;
}

Point3D::~Point3D()
{
}

Point3D::Point3D(double a) 
{
	x = a;
	y = a;
	z = a;
}

Point3D::Point3D(double a, double b, double c) 
{
	x = a;
	y = b;
	z = c;
}

Vector3D Point3D::operator-(Point3D p)
{
	return Vector3D(x-p.x,y-p.y,z-p.z);
}

Point3D Point3D::operator+(Vector3D p)
{
	return Point3D(x + p.x, y+p.y, z+p.z);
}
