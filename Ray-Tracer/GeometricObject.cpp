#include "GeometricObject.h"

GeometricObject::GeometricObject() :color(black) {}

GeometricObject::GeometricObject(const GeometricObject& _o) : color(_o.color) {}

GeometricObject::~GeometricObject() {}

GeometricObject& GeometricObject::operator=(const GeometricObject& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	color = rhs.color;
	return (*this);
}

void GeometricObject::stablishColor(const ColorRGB& _c)
{
	color = _c;
}

void GeometricObject::stablishColor(const float _r, const float _g, const float _b)
{
	color.r = _r;
	color.g = _g;
	color.b = _b;
}

ColorRGB GeometricObject::getColor()
{
	return color;
}
