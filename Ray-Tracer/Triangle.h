#pragma once
#include "GeometricObject.h"
#include "Point3D.h"

class Triangle : public GeometricObject
{
public:
	Triangle();
	Triangle(const Point3D&, const Point3D&, const Point3D&);
	~Triangle();
	bool impact(const Ray&, double&, ShadeRec&)const;
	Point3D v0, v1, v2;
	Vector3D normal;
};