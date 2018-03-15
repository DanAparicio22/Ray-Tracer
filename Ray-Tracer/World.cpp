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

	vp.stablishRhor(900);
	vp.stablishRver(800);
	vp.stablishS(0.4);
	font_color = white;
	tracer_ptr = new VariousObjects(this);
	Sphere* e1 = new Sphere;
	e1->stablishCenter(0.0, 0.0, 0.0);
	e1->stablishRadius(70.0);
	addGeometricObject(e1);
	Sphere* e2 = new Sphere;
	e2->stablishCenter(90.0, 0.0, -95.0);
	e2->stablishRadius(90.0);
	addGeometricObject(e2);
	Point3D v0(-100.0, 0.0, 0.0);
	Point3D v1(100.0, 0.0, 0.0);
	Point3D v2(0.0, 150.0, 0.0);
	Triangle* t = new Triangle(v0, v1, v2);
	addGeometricObject(t);
	SpotLight* ptrLuzPuntual = new SpotLight;
	ptrLuzPuntual->stablishUbication(0.0, 100.0, 200.0);
	ptrLuzPuntual->stablishColor(1.0, 0.0, 0.0);
	addLight(ptrLuzPuntual);

}

void World::drawScene() const
{
	Output salida;
	int dpi = 72;
	int n = vp.rHor * vp.rVer;
	ColorRGB *colores = new ColorRGB[n];
	ColorRGB colorPixel;
	Ray	 rayo;
	int Rhor = vp.rHor;
	int Rver = vp.rVer;
	float s = vp.s;
	float zw = 800;
	rayo.vecD = Vector3D(0.0, 0.0, -1.0);
	for (int fila = 0; fila < Rver; fila++)
	{
		for (int col = 0; col < Rhor; col++)
		{
			double x_w = vp.s * (col - vp.rHor / 2 + 0.5);
			double y_w = vp.s * (fila - vp.rVer / 2 + 0.5);
			double z_w = 100.0;	
			Point3D O(x_w, y_w, z_w);
			rayo.O = O;
			colorPixel = tracer_ptr->trace_ray(rayo);

			colores[fila * Rhor + col] = colorPixel;
		}
	}
	salida.saveBmp("escena.bmp", Rhor, Rver, dpi, colores);
}

void World::addLight(Light* ptrLuz)
{
	lights.push_back(ptrLuz);
}

ShadeRec World::impactObjects(const Ray& rayo)
{
	ShadeRec sr(*this);
	double t;
	Vector3D normal;
	Point3D puntoImpactoLocal;
	double tmin = kHugeValue;
	int numObjetos = objects.size();
	for (int j = 0; j < numObjetos; j++)
	{
		if (objects[j]->impact(rayo, t, sr) && (t < tmin))
		{
			//sr.normal = sr.normal;
			//sr.t = t;
			//sr.puntoImpactoLocal = sr.puntoImpactoLocal;
			sr.impactAnObject = true;
			tmin = t;
			//sr.puntoImpactoLocal = rayo.O + rayo.vecD*t;
			normal = sr.normal;
			puntoImpactoLocal = sr.impactLocalPoint;
			//sr.normal.Mostrar();
			//sr.color = objetos[j]->obtenerColor();
		}
		if (sr.impactAnObject) {
			sr.t = tmin;
			sr.normal = normal;
			sr.impactLocalPoint = puntoImpactoLocal;
		}
	}

	return sr;
}

void World::deleteObjects() {
	int num_objects = objects.size();
	for (int j = 0; j < num_objects; j++) {
		delete objects[j];
		objects[j] = NULL;
	}
	objects.erase(objects.begin(), objects.end());
}

void World::deleteLights() {
	int num_lights = lights.size();
	for (int j = 0; j < num_lights; j++) {
		delete lights[j];
		lights[j] = NULL;
	}
	lights.erase(lights.begin(), lights.end());
}

