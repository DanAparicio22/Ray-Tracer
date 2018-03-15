#include "Tracer.h"

Tracer::Tracer(): world_ptr(NULL) {}

Tracer::Tracer(World* _worldPtr): world_ptr(_worldPtr) {}

Tracer::~Tracer(void) {
	if (world_ptr) 
	{
		world_ptr = NULL;
	}
}

ColorRGB Tracer::trace_ray(const Ray& ray) const {
	return (black);
}

ColorRGB Tracer::trace_ray(const Ray ray, const int depth) const {
	return (black);
}

ColorRGB Tracer::trace_ray(const Ray &, Light * light) const
{
	return (black);
}
