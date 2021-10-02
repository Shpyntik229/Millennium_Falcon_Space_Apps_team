#pragma once
#include <vector>
#include <array>
#include <cmath>

extern const double PI;

struct Point3D
{
	double x, y, z;
	Point3D operator+(const Point3D& a);
	Point3D operator-(const Point3D& a);
};

struct Point2D
{
	double x, y;
};

struct TriangleVertices
{
	std::size_t a, b, c;
};

class Mesh
{
public:
	Mesh(const std::vector<Point3D>& vertices, const std::vector<TriangleVertices>& triangles);
	std::vector<Point3D>& getVertices();
	std::vector<TriangleVertices>& getTriangles();

private:
	std::vector<Point3D> m_vertices;
	std::vector<TriangleVertices> m_triangles;
};

double scalar(const Point3D& a, const Point3D& b);
double scalar(const Point2D& a, const Point2D& b);

Point3D cross_mult(const Point3D& a, const Point3D& b);

double determinate3(const std::array<double, 4>& matrix);
double determinate9(const std::array<double, 9>& matrix);

Point3D CalcNormals(Point3D a, Point3D b, Point3D c)
{
	double wrki;
	Point3D v1, v2;

	v1.x = a.x - b.x;
	v1.y = a.y - b.y;
	v1.z = a.z - b.z;

	v2.x = b.x - c.x;
	v2.y = b.y - c.y;
	v2.z = b.z - c.z;

	wrki = sqrt(pow((v1.y * v2.z - v1.z * v2.y),2) + pow((v1.z * v2.x - v1.x * v2.z),2) + pow((v1.x * v2.y - v1.y * v2.x),2));
	const double n_x = (v1.y * v2.z - v1.z * v2.y) / wrki;
	const double n_y = (v1.z * v2.x - v1.x * v2.z) / wrki;
	const double n_z = (v1.x * v2.y - v1.y * v2.x) / wrki;

	return { n_x, n_y, n_z };
}