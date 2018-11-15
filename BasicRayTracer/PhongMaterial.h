#pragma once

#include "Material.h"
#include "RBGAColor.h"

class PhongMaterial : public Material
{
public:
	RBGAColor diffuse;

	void Show();
};