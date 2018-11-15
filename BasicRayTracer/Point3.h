#pragma once

class Point3
{
public:
	double x, y, z;

	Point3();
	Point3 operator+(const Point3 &rh);
	Point3 operator-(const Point3 &rh);
	Point3 operator*(const double &rh);
	Point3 operator/(const double &rh);
	double dotProduct(const Point3 &rh);
	void Show();
};