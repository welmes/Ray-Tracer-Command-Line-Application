#pragma once

#include "Object3D.h"
#include "Point3.h"
#include "Ray.h"
#include "ShadeRecord.h"

class Sphere : public Object3D
{
public:
	Point3 center;
	double radius;
	int material_index;

	Sphere();
	void Show();
	bool Hit(Ray r, ShadeRecord &sr);
};