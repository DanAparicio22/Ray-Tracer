#include "ViewPlane.h"

ViewPlane::ViewPlane() : rVer(400), rHor(400), s(1.0) {}

ViewPlane::ViewPlane(const ViewPlane& vp) : rVer(vp.rVer), rHor(vp.rHor), s(vp.s) {}

ViewPlane::ViewPlane(int rVer1, int rHor1, double s1) : rVer(rVer1), rHor(rHor1), s(s1) {}

ViewPlane::~ViewPlane() {}

ViewPlane& ViewPlane::operator=(const ViewPlane& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}
	rHor = rhs.rHor;
	rVer = rhs.rVer;
	s = rhs.s;
	return (*this);
}

void ViewPlane::stablishRhor(const int rHor1)
{
	rHor = rHor1;
}

void ViewPlane::stablishRver(const int rVer1)
{
	rVer = rVer1;
}

void ViewPlane::stablishS(const float s1)
{
	s = s1;
}