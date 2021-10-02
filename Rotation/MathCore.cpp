#include "MathCore.h"

const double PI = std::acos(0);

Mesh::Mesh(const std::vector<Point3D>& vertices, const std::vector<TriangleVertices>& triangles)
	: m_vertices(vertices), m_triangles(triangles)
{
}

std::vector<Point3D>& Mesh::getVertices()
{
	return m_vertices;
}

std::vector<TriangleVertices>& Mesh::getTriangles()
{
	return m_triangles;
}

double scalar(const Point3D& a, const Point3D& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

double scalar(const Point2D& a, const Point2D& b)
{
	return a.x * b.x + a.y * b.y;
}

Point3D cross_mult(const Point3D& a, const Point3D& b)
{
	return { determinate3({a.y, a.z, b.y, b.z}),
			determinate3({a.x, a.z, b.x, b.z}),
			determinate3({a.x, a.y, b.x, b.y}) };
}

double determinate3(const std::array<double, 4>& matrix)
{
	return matrix[0] * matrix[3]
		- matrix[1] * matrix[2];
}

double determinate9(const std::array<double, 9>& matrix)
{
	return matrix[0] * matrix[4] * matrix[8]
		- matrix[0] * matrix[5] * matrix[7]
		- matrix[1] * matrix[3] * matrix[8]
		+ matrix[1] * matrix[5] * matrix[6]
		+ matrix[2] * matrix[3] * matrix[7]
		- matrix[2] * matrix[4] * matrix[6];
}

Point3D Point3D::operator+(const Point3D& a)
{
	return { x + a.x, y + a.y, z + a.z };
}

Point3D Point3D::operator-(const Point3D& a)
{
	return  { x - a.x, y - a.y, z - a.z };
}
