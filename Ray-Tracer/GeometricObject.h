#pragma once
#include "ColorRGB.h"
#include "Point3D.h"
#include "Normal.h"
#include "Ray.h"
#include "ShadeRec.h"
#include "Constants.h"

class GeometricObject
{
protected:
	ColorRGB   color;
	GeometricObject& operator= (const GeometricObject&);
public:
	GeometricObject();
	GeometricObject(const GeometricObject&);
	virtual ~GeometricObject();
	virtual bool impact(const Ray&, double&, ShadeRec&)const = 0;
	void stablishColor(const ColorRGB&);
	void stablishColor(const float, const float, const float);
	ColorRGB getColor();
};