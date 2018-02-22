#include "ColorRGB.h"

ColorRGB::ColorRGB() 
{
	r = 0;
	g = 0;
	b = 0;
}

ColorRGB::~ColorRGB() 
{
}

ColorRGB::ColorRGB(double a) 
{
	r = a;
	g = a;
	b = a;
}

ColorRGB::ColorRGB(double r1, double g1, double b1)
{
	r = r;
	g = g;
	b = b;
}

ColorRGB ColorRGB::operator+(ColorRGB rgb)
{
	return ColorRGB(r+rgb.r, g+rgb.g, b+rgb.b);
}

ColorRGB ColorRGB::operator*(ColorRGB rgb)
{
	return ColorRGB(r * rgb.r, g * rgb.g, b * rgb.b);
}

ColorRGB ColorRGB::operator*(double color)
{
	return ColorRGB(r * color, g * color, b * color);
}

ColorRGB ColorRGB::operator/(double color)
{
	return ColorRGB(r / color, g / color, b / color);
}
