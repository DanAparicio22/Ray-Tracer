#pragma once
#include "Vector3D.h"

class Point3D
{
public:
	double x, y, z;
	Point3D();
	Point3D(const double);
	Point3D(double, double, double);
	Point3D(const Point3D&);
	~Point3D();
	Point3D& operator= (const Point3D&);
	Vector3D operator-(const Point3D&) const;
	Point3D operator+(const Vector3D&) const;
};