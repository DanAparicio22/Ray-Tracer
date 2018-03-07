#pragma once
#include "GeometricObject.h"
#include "ViewPlane.h"
#include "Sphere.h"
#include "Tracer.h"
#include "Sphere.h"
#include "SolarSphere.h"
#include "Light.h"
#include "SpotLight.h"
#include "Output.h"
#include "Triangle.h"
#include <vector>
using namespace std;

class World 
{
	public:
		ViewPlane vp;
		ColorRGB font_color;
		Tracer* tracer_ptr;
		Sphere sphere;
		Triangle triangle;
		vector <Light*> lights;
		vector <GeometricObject*> objects;
		World();
		~World();
		void addGeometricObject(GeometricObject*);
		void construct();
		void drawScene() const;
		void addLight(Light* ptrLuz);

	private:
		void deleteObjects(void);
		void deleteLights(void);
};