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
	double getX() const;
	double getY() const;
	double getZ() const;

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

Point3D CalcNormals(Point3D a, Point3D b, Point3D c);
double CaclLight(Point3D& a, Point3D& b, Point3D& c, double k);