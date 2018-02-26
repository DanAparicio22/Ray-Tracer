#include "SolarSphere.h"

SolarSphere::SolarSphere(void) : Tracer() {}

SolarSphere::SolarSphere(World* worldPtr) : Tracer(worldPtr) {}

SolarSphere::~SolarSphere(void) {}

ColorRGB SolarSphere::trace_ray(const Ray& ray) const {
	ShadeRec sr(*world_ptr);
	double t;
	ColorRGB lightColor(1.0, 1.0, 1.0);
	if (world_ptr->sphere.impact(ray, t, sr))
	{
		Vector3D n = sr.normal;
		Vector3D l = sr.w.lights[0]->getDirection(sr);

		ColorRGB c;
		c.r = 1.00 * lightColor.r * std::max(0.0, n*l);
		c.g = 0.81 * lightColor.g * std::max(0.0, n*l);
		c.b = 0.00 * lightColor.b * std::max(0.0, n*l);
		return (c);
	}
	else
		return (white);
}