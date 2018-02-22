#pragma once
#include <math.h>
class Vector3D
{
	public:
		double x, y, z;

		Vector3D();
		~Vector3D();
		Vector3D(double);
		Vector3D(const Vector3D&);
		Vector3D(double,double,double);

		Vector3D operator *(double);
		double operator *(Vector3D);

		void normalize();
};