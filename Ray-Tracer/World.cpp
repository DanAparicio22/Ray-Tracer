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
	Point3D v0(0.0, 80.0, 0.0);
	Point3D v1(80.0, 80.0, 0.0);
	Point3D v2(0.0, 0.0, 0.0);
	Triangle* t = new Triangle(v0, v1, v2);
	addGeometricObject(t);
	Point3D v01(-80.0, 0.0, 0.0);
	Point3D v11(0.0, 80.0, 0.0);
	Point3D v21(0.0, 0.0, 0.0);
	Triangle* t1 = new Triangle(v01, v11, v21);
	addGeometricObject(t1);
	Point3D v02(-80.0, 0.0, 0.0);
	Point3D v12(0.0, -80.0, 0.0);
	Point3D v22(0.0, 0.0, 0.0);
	Triangle* t2 = new Triangle(v02, v12, v22);
	addGeometricObject(t2);
	Point3D v03(80.0, -80.0, 0.0);
	Point3D v13(0.0, -80.0, 0.0);
	Point3D v23(0.0, 0.0, 0.0);
	Triangle* t3 = new Triangle(v03, v13, v23);
	addGeometricObject(t3);
	Point3D v04(-80.0, 0.0, 80.0);
	Point3D v14(-80.0, 40.0, 0.0);
	Point3D v24(-40.0, 40.0, 0.0);
	Triangle* t4 = new Triangle(v04, v14, v24);
	addGeometricObject(t4);
	SpotLight* ptrLuzPuntual = new SpotLight;
	ptrLuzPuntual->stablishUbication(100.0, 100.0, 200.0);
	ptrLuzPuntual->stablishColor(1.0, 0.0, 0.0);
	addLight(ptrLuzPuntual);
	SpotLight* ptrLuzPuntual2 = new SpotLight;
	ptrLuzPuntual2->stablishUbication(100.0, -100.0, -200.0);
	ptrLuzPuntual2->stablishColor(1.0, 0.0, 0.0);
	addLight(ptrLuzPuntual2);
	/*SpotLight* ptrLuzPuntual3 = new SpotLight;
	ptrLuzPuntual3->stablishUbication(0.0, 0.0, 0.0);
	ptrLuzPuntual3->stablishColor(1.0, 0.0, 0.0);
	addLight(ptrLuzPuntual3);*/
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
				for (int x = 0; x < lights.size(); x++) {
					colorPixel = tracer_ptr->trace_ray(rayo,lights[x]);
					colores[fila * Rhor + col] = colorPixel;
				}
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

