#include <iostream>
#include "Camera.h"
using namespace std;

Camera::Camera()
{
	type = 0;
}

void Camera::Show()
{
	if(type == CAMERA_ORTHOGRAPHIC) cout << "Orthographic Camera:";
	else cout << "Typeless Camera:";
	cout << "\ncenter = ";
	center.Show();
	cout << "\ndirection = ";
	direction.Show();
	cout << "\nup = ";
	up.Show();
	cout << endl;
}