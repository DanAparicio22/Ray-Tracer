#pragma once
#include "GeometricObject.h"
#include <math.h>

class Sphere : public GeometricObject
{
public:
	Point3D C;
	double r;
	Sphere();
	Sphere(Point3D, double);
	Sphere(const Sphere&);
	virtual ~Sphere();
	Sphere& operator= (const Sphere&);
	void stablishCenter(const Point3D&);
	void stablishCenter(const double, const double, const double);
	void stablishRadius(const double);
	bool impact(const Ray&, double&, ShadeRec&)const;
};
