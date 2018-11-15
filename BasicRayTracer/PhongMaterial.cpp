#include <iostream>
#include "PhongMaterial.h"
using namespace std;

void PhongMaterial::Show()
{
	cout << "\nPhong Material:" << endl;
	cout << "id = " << id << endl;
	cout << "type = " << type << endl;
	cout << "diffuse = ";
	diffuse.Show();
	cout << endl;
}