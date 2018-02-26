#pragma once
#include "Tracer.h"
#include "World.h"
#include "ShadeRec.h"
#include "SpotLight.h"
#include <algorithm> 

class SolarSphere : public Tracer {
public:
	SolarSphere(void);
	SolarSphere(World*);
	virtual ~SolarSphere(void);
	virtual ColorRGB trace_ray(const Ray&) const;
};