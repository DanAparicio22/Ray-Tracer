#pragma once
#include "Ray.h"
#include "ShadeRec.h"
#include "Point3D.h"
#include "GeometricObject.h"
class Triangle : public GeometricObject
{
	public:
		Point3D v0, v1, v2;
		Vector3D normal;
		Triangle();
		Triangle(Point3D&, Point3D&, Point3D&);
		Triangle(const Triangle&);
		~Triangle();
		void stablishPoints(const Point3D&, const Point3D&, const Point3D&);
		bool impact(const Ray&, double&, ShadeRec&) const;
		Triangle& operator= (const Triangle&);
};