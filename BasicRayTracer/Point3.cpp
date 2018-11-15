#include <iostream>
#include "Point3.h"
using namespace std;

Point3::Point3()
{
	x = 0;
	y = 0;
	z = 0;
}

Point3 Point3::operator+(const Point3 &rh)
{
	Point3 p;
	p.x = x + rh.x;
	p.y = y + rh.y;
	p.z = z + rh.z;
	return p;
}

Point3 Point3::operator-(const Point3 &rh)
{
	Point3 p;
	p.x = x - rh.x;
	p.y = y - rh.y;
	p.z = z - rh.z;
	return p;
}

Point3 Point3::operator*(const double &rh)
{
	Point3 p;
	p.x = x * rh;
	p.y = y * rh;
	p.z = z * rh;
	return p;
}

Point3 Point3::operator/(const double &rh)
{
	Point3 p;
	p.x = x / rh;
	p.y = y / rh;
	p.z = z / rh;
	return p;
}

double Point3::dotProduct(const Point3&rh)
{
	return (x * rh.x + y * rh.y + z * rh.z);
}

void Point3::Show()
{
	cout << "(" << x << ", " << y << ", " << z << ")";
}