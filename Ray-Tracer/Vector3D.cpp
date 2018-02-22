#include "Vector3D.h"

Vector3D::~Vector3D() 
{
}
Vector3D::Vector3D() 
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3D::Vector3D(double a) 
{
	x = a;
	y = a;
	z = a;
}
Vector3D::Vector3D(double a, double b, double c) 
{
	x = a;
	y = b;
	z = c;
}
Vector3D Vector3D::operator*(double t) 
{
	return Vector3D(x*t,y*t,z*t);
}
double Vector3D::operator*(Vector3D vector) 
{
	return x * vector.x + y * vector.y + z * vector.z;
}
void Vector3D::normalize() 
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}

Vector3D::Vector3D(const Vector3D & vector):x(vector.x),y(vector.y),z(vector.z)
{
	
}
