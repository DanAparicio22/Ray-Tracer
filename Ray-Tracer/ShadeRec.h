#pragma once
class World;

#include "Point3D.h"
#include "Normal.h"
#include "ColorRGB.h"

class ShadeRec
{
public:
	bool impactAnObject;
	Point3D impactLocalPoint;
	Vector3D normal;
	ColorRGB color;
	World& world;
	float t;
	ShadeRec(World&);
	ShadeRec(const ShadeRec&);
	~ShadeRec();
};
