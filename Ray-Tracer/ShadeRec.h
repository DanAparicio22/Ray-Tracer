#pragma once

class World;
#include "Point3D.h"
#include "Normal.h"
#include "ColorRGB.h"
#include "Constants.h"

class ShadeRec
{
	public:
		ShadeRec(World&);
		ShadeRec(const ShadeRec&);
		~ShadeRec();
		bool impactAnObject;
		Point3D impactLocalPoint;
		Vector3D normal;
		ColorRGB color;
		World& w;
};