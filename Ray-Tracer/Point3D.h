#pragma once
#include "Vector3D.h"
class Point3D 
{
	public:
		double x, y, z;

		Point3D();
		~Point3D();
		Point3D(double);
		Point3D(double,double,double);

		Vector3D operator-(Point3D);
		Point3D operator+(Vector3D);
};