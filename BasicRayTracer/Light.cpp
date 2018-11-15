#include <iostream>
#include "Light.h"
using namespace std;

Light::Light()
{
	type = 0;
}

void Light::Show()
{
	cout << "Light:" << endl;
	cout << "type = " << type << endl;
	cout << "position = ";
	position.Show();
	cout << endl;
	cout << "diffuse = ";
	diffuse.Show();
	cout << endl;
}