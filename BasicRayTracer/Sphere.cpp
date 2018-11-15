#include <iostream>
#include <math.h>
#include "Sphere.h"
#include "TokenReader.h"
#include "Scene.h"
using namespace std;

extern TokenReader tr;

Sphere::Sphere()
{
	radius = 0;
	material_index = 0;
}

void Sphere::Show()
{
	cout << "Sphere:" << endl;
	cout << "center = ";
	center.Show();
	cout << endl;
	cout << "radius = " << radius << endl;
	cout << "material_index = " << material_index << endl;
}

bool Sphere::Hit(Ray r, ShadeRecord &sr)
{
	double t;
	Point3 temp = r.position - center;
	double a = r.direction.dotProduct(r.direction); // Length of ray squared
	double b = 2.0 * temp.dotProduct(r.direction);
	double c = temp.dotProduct(temp) - radius * radius;
	double disc = b * b - 4.0 * a * c;
	if (disc < 0) return false;
	else
	{
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;
		if (t > 0)
		{
			sr.tmin = t;
			sr.normal = (temp + r.direction * t) / radius;
			sr.hit_point = r.position + r.direction * t;
			sr.material = tr.scene.materials[material_index];
			return true;
		}
		t = (-b + e) / denom;
		if (t > 0)
		{
			sr.tmin = t;
			sr.normal = (temp + r.direction * t) / radius;
			sr.hit_point = r.position + r.direction * t;
			sr.material = tr.scene.materials[material_index];
			return true;
		}
	}
	return false;
}