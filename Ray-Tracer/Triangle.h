#pragma once
#include "Ray.h"
#include "ShadeRec.h"
#include "Point3D.h"
class Triangle {
	public:
		Point3D v0, v1, v2;
		Triangle();
		~Triangle();
		bool impact(const Ray&, double&, ShadeRec&) const;
};