#include "Vector3D.h"

Vector3D::~Vector3D() {}
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
Vector3D Vector3D::operator*(double t) const 
{
	return Vector3D(x*t,y*t,z*t);
}
double Vector3D::operator*(Vector3D vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}
Vector3D Vector3D::operator+(const Vector3D & _v) const
{
	return(Vector3D(x + _v.x, y + _v.y, z + _v.z));
}

Vector3D Vector3D::operator/(const double _a) const
{
	return (Vector3D(x / _a, y / _a, z / _a));
}

void Vector3D::show()
{
	cout << "< ";
	cout << x;
	cout << ", ";
	cout << y;
	cout << ", ";
	cout << z;
	cout << " >";
}

void Vector3D::normalize() 
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length;
	y /= length;
	z /= length;
}

Vector3D::Vector3D(const Vector3D & vector):x(vector.x),y(vector.y),z(vector.z){}
