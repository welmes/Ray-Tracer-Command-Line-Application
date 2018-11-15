#include <iostream>
#include "Ray.h"
using namespace std;

void Ray::Show()
{
	cout << "Ray: position = ";
	position.Show();
	cout << ", direction = ";
	direction.Show();
	cout << endl;
}

void Ray::calculateRay(int col, int row, ViewPlane vp)
{
	position.x = col * vp.pixelSize - (vp.pixelSize * vp.width / 2) + (vp.pixelSize / 2);
	position.y = row * vp.pixelSize - (vp.pixelSize * vp.height / 2) + (vp.pixelSize / 2);
	position.z = 0;
	direction.x = 0;
	direction.y = 0;
	direction.z = 1;
}