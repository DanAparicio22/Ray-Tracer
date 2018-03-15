#include "SpotLight.h"

SpotLight::SpotLight(): Light(), ls(1.0), color(1.0), ubicacion(0, 1, 0) {}

SpotLight::~SpotLight() {}

Vector3D SpotLight::getDirection(ShadeRec& sr)
{
	return (ubicacion - sr.impactLocalPoint).hat();
}

ColorRGB SpotLight::L(ShadeRec& sr)
{
	return(color*ls);
}

void SpotLight::stablishColor(const ColorRGB& c)
{
	color = c;
}

void SpotLight::stablishColor(float r, float g, float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

void SpotLight::stablishUbication(Point3D p)
{
	ubicacion = p;
}

void SpotLight::stablishUbication(float x, float y, float z)
{
	ubicacion.x = x;
	ubicacion.y = y;
	ubicacion.z = z;
}