#include "GeometricObject.h"

GeometricObject::GeometricObject() : color(black) {}

GeometricObject::GeometricObject(const GeometricObject& obj) : color(obj.color) {}

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

void GeometricObject::stablishColor(const ColorRGB& c)
{
	color = c;
}

void GeometricObject::stablishColor(const float r, const float g, const float b)
{
	color.r = r;
	color.g = g;
	color.b = b;
}

ColorRGB GeometricObject::getColor()
{
	return color;
}