#pragma once

#include <vector>
#include "Ray.h"
using namespace std;

class RayTracer
{
public:
	vector<Ray*> rays;

	~RayTracer();
	void initializeRays();
	void traceRays();
};