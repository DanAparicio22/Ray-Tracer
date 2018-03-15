#pragma once
#include "Light.h"

class SpotLight : public Light
{
private:
	float ls;
	ColorRGB color;
	Point3D ubicacion;
public:
	SpotLight();
	~SpotLight();
	Vector3D getDirection(ShadeRec&);
	ColorRGB L(ShadeRec&);
	void stablishColor(const ColorRGB&);
	void stablishColor(float, float, float);
	void stablishUbication(Point3D);
	void stablishUbication(float, float, float);
};