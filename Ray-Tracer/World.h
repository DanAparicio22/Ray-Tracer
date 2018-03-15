#pragma once
#include <vector>
#include "ViewPlane.h"
#include "ColorRGB.h"
#include "Tracer.h"
#include "GeometricObject.h"
#include "Ray.h"
#include "Light.h"
#include "SpotLight.h"
#include "Constants.h"
#include "Sphere.h"
#include "Triangle.h"
#include "VariousObjects.h"
#include "Vector3D.h"
#include "Point3D.h"
#include "Normal.h"
#include "ShadeRec.h"
#include <math.h>
#include "Output.h"
using namespace std;

class World
{
public:
	ViewPlane vp;
	ColorRGB font_color;
	Tracer*	tracer_ptr;
	vector<GeometricObject*> objects;
	vector<Light*> lights;
	World();
	~World();
	void addGeometricObject(GeometricObject*);
	void construct();
	void drawScene() const;
	void addLight(Light*);
	ShadeRec impactObjects(const Ray&);
private:
	void deleteObjects(void);
	void deleteLights(void);
};