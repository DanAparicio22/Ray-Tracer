#include "Ray.h"

Ray::Ray()
{
	p.x = 0;
	p.y = 0;
	p.z = 0;
	d.x = 0;
	d.y = 0;
	d.z = 1;
}

Ray::~Ray()
{
}

Ray::Ray(Point3D q, Vector3D v)
{
	p = q;
	d = v;
}
