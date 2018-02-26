#include "Light.h"

Light::Light() {}

Light::~Light() {}

Light& Light::operator=(const Light& rhs)
{
	if (this == &rhs)
		return (*this);

	return (*this);
}

ColorRGB Light::L(ShadeRec& s) {
	return (black);
}