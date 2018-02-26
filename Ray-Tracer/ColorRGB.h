#pragma once

class ColorRGB
{
	public:
		double r, g, b;
		ColorRGB();
		~ColorRGB();
		ColorRGB(double);
		ColorRGB(double,double,double);
		ColorRGB(const ColorRGB &);
		ColorRGB operator+(const ColorRGB&) const;
		ColorRGB operator*(const ColorRGB&) const;
		ColorRGB operator*(const double) const;
		ColorRGB operator/(const double) const;
		ColorRGB& operator+= (const ColorRGB&);
		ColorRGB& operator= (const ColorRGB&);
};