#include "World.h"

World::World() : font_color(black), tracer_ptr(NULL) {}

World::~World()
{
	if (tracer_ptr) {
		delete tracer_ptr;
		tracer_ptr = NULL;
	}

	deleteObjects();
	deleteLights();
}
void World::addGeometricObject(GeometricObject* ptr_objeto)
{
	objects.push_back(ptr_objeto);
}

void World::construct(void) {

	vp.stablishRhor(800);
	vp.stablishRver(700);
	vp.stablishS(0.4);
	font_color = white;
	tracer_ptr = new SolarSphere(this);
	sphere.stablishCenter(0.0);
	sphere.stablishRadius(90);
	SpotLight* ptrSpotLight = new SpotLight();
	ptrSpotLight->stablishUbication(0.0, 160.0, 200.0);
	ptrSpotLight->stablishColor(255.0, 0.0, 0.0);
	addLight(ptrSpotLight);
}

void World::drawScene() const
{
	Output output;
	int dpi = 72;
	int n = vp.rHor * vp.rVer;
	ColorRGB *colors = new ColorRGB[n];
	ColorRGB pixelColor;
	Ray ray;
	int Rhor = vp.rHor;
	int Rver = vp.rVer;
	float s = vp.s;
	float zw = 100;
	ray.v = Vector3D(0.0, 0.0, -1.0);
	for (int row = 0; row < Rver; row++)
	{
		for (int col = 0; col < Rhor; col++)
		{
			double x_w = vp.s * (col - vp.rHor / 2 + 0.5);
			double y_w = vp.s * (row - vp.rVer / 2 + 0.5);
			double z_w = 100.0;	
			Point3D o(x_w, y_w, z_w);		
			ray.p = o;
			pixelColor = tracer_ptr->trace_ray(ray);
			colors[row * Rhor + col] = pixelColor;
		}
	}
	output.saveBmp("escena.bmp", Rhor, Rver, dpi, colors);
}

void World::addLight(Light* ptrLuz)
{
	lights.push_back(ptrLuz);
}

void World::deleteObjects(void) {
	int num_objects = objects.size();
	for (int j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = NULL;
	}
	objects.erase(objects.begin(), objects.end());
}

void World::deleteLights(void) {
	int num_lights = lights.size();
	for (int j = 0; j < num_lights; j++) {
		delete lights[j];
		lights[j] = NULL;
	}
	lights.erase(lights.begin(), lights.end());
}

