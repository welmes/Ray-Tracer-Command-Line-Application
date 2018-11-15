#include <iostream>
#include "ViewPlane.h"
using namespace std;

ViewPlane::ViewPlane()
{
	width = 0;
	height = 0;
	pixelSize = 0;
}

void ViewPlane::Show()
{
	cout << "View Plane:\n";
	cout << "width = " << width << endl;
	cout << "height = " << height << endl;
	cout << "pixelsize = " << pixelSize << endl;
}