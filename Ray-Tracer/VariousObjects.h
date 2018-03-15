#pragma once
#include "Tracer.h"
#include "World.h"
#include <algorithm> 
#include <iostream>
using std::cout;

class VariousObjects : public Tracer
{
public:
	VariousObjects();
	VariousObjects(World*);
	~VariousObjects();
	virtual ColorRGB trace_ray(const Ray&) const;
};