#pragma once

class ViewPlane
{
public:
	ViewPlane();
	ViewPlane(const ViewPlane&);
	ViewPlane(int, int, double);
	~ViewPlane();
	ViewPlane& operator= (const ViewPlane&);
	void stablishRhor(const int);
	void stablishRver(const int);
	void stablishS(const float);
	int rVer;
	int rHor;
	double s;
};
