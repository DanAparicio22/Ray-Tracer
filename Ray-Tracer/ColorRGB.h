#pragma once

class ColorRGB
{
public:
	double r, g, b;
	ColorRGB();
	ColorRGB(double);
	ColorRGB(double, double, double);
	ColorRGB(const ColorRGB &);
	~ColorRGB();
	ColorRGB& operator= (const ColorRGB&);
	ColorRGB operator+ (const ColorRGB&) const;
	ColorRGB& operator+= (const ColorRGB&);
	ColorRGB operator* (const float)const;
	ColorRGB operator/ (const float) const;
	ColorRGB operator* (const ColorRGB&)const;
};