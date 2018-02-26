#include "ColorRGB.h"

ColorRGB::ColorRGB() : r(0.0), g(0.0), b(0.0) {}

ColorRGB::~ColorRGB() {}

ColorRGB::ColorRGB(double a) : r(a), g(a), b(a) {}

ColorRGB::ColorRGB(double r1, double g1, double b1) : r(r1), g(g1), b(b1) {}

ColorRGB::ColorRGB(const ColorRGB &c) : r(c.r), g(c.g), b(c.b) {}

ColorRGB ColorRGB::operator+(const ColorRGB& c) const
{
	return ColorRGB(r + c.r, g + c.g, b + c.b);
}

ColorRGB ColorRGB::operator*(const ColorRGB& c) const
{
	return ColorRGB(r * c.r, g * c.g, b * c.b);
}

ColorRGB ColorRGB::operator*(const double a) const
{
	return ColorRGB(r*a, g*a, b*a);
}

ColorRGB ColorRGB::operator/(const double a) const
{
	return ColorRGB(r / a, g / a, b / a);
}

ColorRGB & ColorRGB::operator+=(const ColorRGB &c)
{
	r += c.r;
	g += c.g;
	b += c.b;
	return (*this);
}

ColorRGB & ColorRGB::operator=(const ColorRGB &rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	r = rhs.r;
	g = rhs.g;
	b = rhs.b;
	return (*this);
}
