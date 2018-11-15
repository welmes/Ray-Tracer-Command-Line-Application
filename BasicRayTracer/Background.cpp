#include <iostream>
#include "Background.h"
using namespace std;

void Background::Show()
{
	cout << "Background:" << endl;
	cout << "color = ";
	color.Show();
	cout << endl;
}