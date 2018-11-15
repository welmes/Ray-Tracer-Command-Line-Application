#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{
	for (size_t i = 0; i < lights.size(); i++) {
		delete lights[i];
	}
	for (size_t i = 0; i < materials.size(); i++) {
		delete materials[i];
	}
	for (size_t i = 0; i < objects.size(); i++) {
		delete objects[i];
	}
}