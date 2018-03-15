#pragma once
#include "Vector3D.h"
#include "ColorRGB.h"
#include "ShadeRec.h"
#include "Constants.h"

class Light
{
public:
	Light();
	virtual ~Light();
	Light& operator=(const Light&);
	virtual Vector3D getDirection(ShadeRec&) = 0;
	virtual ColorRGB L(ShadeRec&);
};