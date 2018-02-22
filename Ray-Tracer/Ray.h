#pragma once
#include "Point3D.h"
#include "Vector3D.h"

class Ray 
{
	public:
		Point3D p;
		Vector3D d;

		Ray();
		~Ray();
		Ray(Point3D, Vector3D);
};