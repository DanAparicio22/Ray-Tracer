#pragma once
#include "Constants.h"
#include "Ray.h"
#include "ColorRGB.h"
#include <iostream>

class World;

class Tracer {
protected:
	World * world_ptr;
public:
	Tracer();
	Tracer(World*);
	virtual	~Tracer(void);
	virtual ColorRGB trace_ray(const Ray&) const;
	virtual ColorRGB trace_ray(const Ray, const int) const;
};