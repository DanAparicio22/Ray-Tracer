#include "VariousObjects.h"

VariousObjects::VariousObjects(): Tracer() {}

VariousObjects::VariousObjects(World* _worldPtr): Tracer(_worldPtr) {}

VariousObjects::~VariousObjects() {}

ColorRGB VariousObjects::trace_ray(const Ray& ray)const
{

	ShadeRec sr(world_ptr->impactObjects(ray));
	ColorRGB colorLuz(1.0, 0.4, 0.1);
	if (sr.impactAnObject)
	{

		sr.color.r = sr.color.r * std::max(0.0, sr.normal*world_ptr->lights[0]->getDirection(sr));
		sr.color.g = sr.color.g * std::max(0.0, sr.normal*world_ptr->lights[0]->getDirection(sr));
		sr.color.b = sr.color.b * std::max(0.0, sr.normal*world_ptr->lights[0]->getDirection(sr));
		return (sr.color);
	}
	else
	{
		return world_ptr->font_color;
	}
}