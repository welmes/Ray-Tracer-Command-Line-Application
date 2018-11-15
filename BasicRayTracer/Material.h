#pragma once

enum
{
	MATERIAL_NULL = 0,
	MATERIAL_PHONG
};

class Material
{
public:
	int id, type;

	Material();
	void Show();
};