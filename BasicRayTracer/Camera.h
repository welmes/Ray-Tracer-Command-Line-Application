#pragma once

#include "Point3.h"

enum
{
	CAMERA_NULL = 0,
	CAMERA_ORTHOGRAPHIC
};

class Camera
{
public:
	int type;
	Point3 center, direction, up;

	Camera();
	void Show();
};