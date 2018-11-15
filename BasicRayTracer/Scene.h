#pragma once

#include <vector>
#include "Camera.h"
#include "ViewPlane.h"
#include "Background.h"
#include "Light.h"
#include "Material.h"
#include "Object3D.h"
using namespace std;

class Scene
{
public:
	Camera camera;
	ViewPlane view_plane;
	Background background;
	vector<Light*> lights;
	vector<Material*> materials;
	vector<Object3D*> objects;

	Scene();
	~Scene();
private:
};