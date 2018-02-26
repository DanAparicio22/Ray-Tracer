#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Ray 
{
	public:
		Point3D p;
		Vector3D v;
		Ray();
		~Ray();
		Ray(const Point3D&, const Vector3D&);
		Ray(const Ray&);
		Ray& operator=(const Ray&);
};