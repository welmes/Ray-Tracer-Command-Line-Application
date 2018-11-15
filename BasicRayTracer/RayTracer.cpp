#include "RayTracer.h"
#include "TokenReader.h"
#include "Scene.h"

extern TokenReader tr;
extern bool verbose;

RayTracer::~RayTracer()
{
	for (size_t i = 0; i < rays.size(); i++) {
		delete rays[i];
	}
}

void RayTracer::initializeRays()
{
	if (verbose) cout << "Initializing rays..." << endl;
	for (int row = 0; row < tr.scene.view_plane.height; row++)
	{
		for (int col = 0; col < tr.scene.view_plane.width; col++)
		{
			Ray *r = new Ray();
			r->calculateRay(col, row, tr.scene.view_plane);
			rays.push_back(r);
			if (verbose) r->Show();
		}
	}
}

void RayTracer::traceRays()
{
	if (verbose) cout << "Tracing rays... (Placeholder)" << endl;
}