#include "ViewPlane.h"

ViewPlane::ViewPlane() :rVer(400), rHor(400), s(1.0) {}

ViewPlane::ViewPlane(const ViewPlane& vp): rVer(vp.rVer), rHor(vp.rHor), s(vp.s) {}

ViewPlane::ViewPlane(int _Rver, int _Rhor, double _s) : rVer(_Rver), rHor(_Rhor), s(_s) {}

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

void ViewPlane::stablishRhor(const int _Rhor)
{
	rHor = _Rhor;
}

void ViewPlane::stablishRver(const int _Rver)
{
	rVer = _Rver;
}

void ViewPlane::stablishS(const float _s)
{
	s = _s;
}