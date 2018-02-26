#pragma once
#include "Constants.h"
#include "Ray.h"
#include "ColorRGB.h"
class World; 

class Tracer
{
	public:
		Tracer(void);
		Tracer(World* _world_ptr);
		virtual	~Tracer(void);
		virtual ColorRGB trace_ray(const Ray& ray) const;
		virtual ColorRGB trace_ray(const Ray ray, const int depth) const;

	protected:
		World * world_ptr;
};