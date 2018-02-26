#pragma once
#include "Point3D.h"

class Normal
{
	public:
		double x, y, z;
		Normal();
		~Normal();
		Normal(double);
		Normal(double, double, double);
		Normal(const Normal &);
		Normal(const Vector3D &);
		Normal& operator= (const Normal&);
		Normal& operator= (const Vector3D&);
		Normal& operator= (const Point3D&);
		Normal operator- () const;
		Normal operator+ (const Normal&) const;
		Normal& operator+= (const Normal&);
		double operator* (const Vector3D&) const;
		Normal operator* (const double) const;
		void normalize();
};