#pragma once

#include <stddef.h>
#include "Point3.h"
#include "Material.h"
using namespace std;

class ShadeRecord
{
public:
	double tmin;
	Point3 hit_point;
	Point3 normal;
	Material *material;

	ShadeRecord();
};