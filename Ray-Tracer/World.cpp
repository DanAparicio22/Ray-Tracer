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
	Point3D v0(5.0, 0.0, 0.0);
	Point3D v1(55.0, 0.0, 0.0);
	Point3D v2(30.0, 40.0, 0.0);
	Triangle* t1 = new Triangle(v0, v1, v2);
	t1->stablishColor(0.51,0.49,0.91);
	Point3D v3(-5.0, 0.0, 99.9);
	Point3D v4(-55.0, 0.0, 99.9);
	Point3D v5(-30.0, 40.0, 99.9);
	Triangle* t2 = new Triangle(v3, v4, v5);
	t2->stablishColor(0.51,0.49,0.91);
	Point3D v6(-25.0, 40.0, 99.9);
	Point3D v7(25.0, 40.0, 99.9);
	Point3D v8(0.0, 0.0, 99.9);
	Triangle* t3 = new Triangle(v6, v7, v8);
	t3->stablishColor(0.49, 0.91, 0.52);
	Point3D v9(-35.0, 40.0, 0.0);
	Point3D v10(-85.0, 40.0, 0.0);
	Point3D v11(-60.0, 0.0, 0.0);
	Triangle* t4 = new Triangle(v9, v10, v11);
	t4->stablishColor(0.49, 0.91, 0.52);
	Point3D v12(35.0, 40.0, 99.9);
	Point3D v13(85.0, 40.0, 99.9);
	Point3D v14(60.0, 0.0, 99.9);
	Triangle* t5 = new Triangle(v12, v13, v14);
	t5->stablishColor(0.49, 0.91, 0.52);
	Point3D v15(65.0, 0.0, 0.0);
	Point3D v16(115.0, 0.0, 0.0);
	Point3D v17(90.0, 40.0, 0.0);
	Triangle* t6 = new Triangle(v15, v16, v17);
	t6->stablishColor(0.51, 0.49, 0.91);
	Point3D v18(-65.0, 0.0, 99.9);
	Point3D v19(-115.0, 0.0, 99.9);
	Point3D v20(-90.0, 40.0, 99.9);
	Triangle* t7 = new Triangle(v18, v19, v20);
	t7->stablishColor(0.51, 0.49, 0.91);
	Point3D v21(-25.0, 45.0, 0.0);
	Point3D v22(25.0, 45.0, 0.0);
	Point3D v23(0.0, 85.0, 0.0);
	Triangle* t8 = new Triangle(v21, v22, v23);
	t8->stablishColor(0.49, 0.91, 0.52);
	Point3D v24(5.0,-5.0, 99.9);
	Point3D v25 (55.0, -5.0,99.);
	Point3D v26(30.0, -45.0, 99.9);
	Triangle* t9 = new Triangle(v24, v25, v26);
	t9->stablishColor(0.49, 0.91, 0.52);
	Point3D v27(-5.0, -5.0, 0.0);
	Point3D v28(-55.0, -5.0, 0.0);
	Point3D v29(-30.0, -45.0, 0.0);
	Triangle* t10 = new Triangle(v27, v28, v29);
	t10->stablishColor(0.49, 0.91, 0.52);
	Point3D v30(-25.0, -45.0, 0.0);
	Point3D v31(25.0, -45.0, 0.0);
	Point3D v32(0.0, -5.0, 0.0);
	Triangle* t11 = new Triangle(v30, v31, v32);
	t11->stablishColor(0.51, 0.49, 0.91);
	Point3D v33(-25.0, -50.0, 99.9);
	Point3D v34(25.0, -50.0, 99.9);
	Point3D v35(0.0, -90.0, 0.0);
	Triangle* t12 = new Triangle(v33, v34, v35);
	t12->stablishColor(0.49, 0.91, 0.52);
	Point3D v36(-5.0, -90.0, 99.9);
	Point3D v37(-55.0, -90.0, 99.9);
	Point3D v38(-30.0, -50.0, 99.9);
	Triangle* t13 = new Triangle(v36, v37, v38);
	t13->stablishColor(0.51, 0.49, 0.91);
	Point3D v39(5.0, -90.0, 0.0);
	Point3D v40(55.0, -90.0, 0.0);
	Point3D v41(30.0, -50.0, 0.0);
	Triangle* t14 = new Triangle(v39, v40, v41);
	t14->stablishColor(0.51, 0.49, 0.91);

	addGeometricObject(t1);
	addGeometricObject(t2);
	addGeometricObject(t3);
	addGeometricObject(t4);
	addGeometricObject(t5);
	addGeometricObject(t6);
	addGeometricObject(t7);
	addGeometricObject(t8);
	addGeometricObject(t9);
	addGeometricObject(t10);
	addGeometricObject(t11);
	addGeometricObject(t12);
	addGeometricObject(t13);
	addGeometricObject(t14);

	SpotLight* ptrLuzPuntual = new SpotLight;
	ptrLuzPuntual->stablishUbication(0.0, 0.0,60.0);
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
			sr.impactAnObject = true;
			tmin = t;
			sr.impactLocalPoint = rayo.O + rayo.vecD*t;
			normal = sr.normal;
			puntoImpactoLocal = sr.impactLocalPoint;
			sr.color = objects[j]->getColor();
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

