#pragma once
#include <math.h>
#include <iostream>
using std::cout;

class Vector3D
{
public:
	double x, y, z;
	Vector3D();		
	Vector3D(double);	
	Vector3D(double, double, double);
	Vector3D(const Vector3D&);
	~Vector3D();
	Vector3D operator*(double) const;
	double operator*(const Vector3D&) const;
	Vector3D operator+ (const Vector3D&) const;
	Vector3D operator/ (const double)const;
	Vector3D& hat();
	void normalize();
	void show();
	Vector3D operator^ (const Vector3D&) const;
	
};