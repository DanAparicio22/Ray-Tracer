#pragma once
class ColorRGB
{
	public:
		double r, g, b;

		ColorRGB();
		~ColorRGB();
		ColorRGB(double);
		ColorRGB(double,double,double);

		ColorRGB operator+(ColorRGB);
		ColorRGB operator*(ColorRGB);
		ColorRGB operator*(double);
		ColorRGB operator/(double);
};