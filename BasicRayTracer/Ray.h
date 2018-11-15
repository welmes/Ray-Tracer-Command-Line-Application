#pragma once

#include "Point3.h"
#include "ViewPlane.h"

class Ray
{
public:
	Point3 position;
	Point3 direction;

	void Show();
	void calculateRay(int col, int row, ViewPlane vp);
};