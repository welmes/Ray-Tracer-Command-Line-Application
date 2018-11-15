#pragma once

#include "Point3.h"
#include "RBGAColor.h"

enum
{
	LIGHT_NULL = 0,
	LIGHT_PHONG_POINT
};

class Light
{
public:
	int type;
	Point3 position;
	RBGAColor ambient, diffuse, specular;

	Light();
	void Show();
};