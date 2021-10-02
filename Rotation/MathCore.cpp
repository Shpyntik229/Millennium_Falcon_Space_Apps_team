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

double cross_mult(const Point2D& a, const Point2D& b)
{
	return a.x * b.y - a.y * b.y;
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

double dist(const Point2D& a)
{
	return std::sqrt(a.x * a.x + a.y * a.y);
}

double getAngle(const Point2D& a, const Point2D& b)
{
	return acos(scalar(a, b) / dist(a) / dist(b));
}

Point3D Point3D::operator+(const Point3D& a)
{
	return { x + a.x, y + a.y, z + a.z };
}

Point3D Point3D::operator-(const Point3D& a)
{
	return  { x - a.x, y - a.y, z - a.z };
}

double Point3D::getX() const
{
	return x;
}

double Point3D::getY() const
{
	return y;
}

double Point3D::getZ() const
{
	return z;
}

double CaclLight(Point3D& a, Point3D& b, Point3D& c, double k)
{
	const auto triangleNormal = CalcNormals(a, b, c);
	if (triangleNormal.getY() < 0)
	{
		return 0;
	}
	else
	{
		const Point3D cameraNormal{ 0, 1, 0 };
		const double A = sqrt(pow(a.getX() - b.getX(), 2) + pow(a.getZ() - b.getZ(), 2));
		const double B = sqrt(pow(b.getX() - c.getX(), 2) + pow(b.getZ() - c.getZ(), 2));
		const double C = sqrt(pow(a.getX() - c.getX(), 2) + pow(a.getZ() - c.getZ(), 2));
		const auto P = (A + B + C) / 2;
		auto S = sqrt(((P - A) * (P - C) * (P - B))) / 2;
		auto cosA = (scalar(triangleNormal, cameraNormal)) /
			(sqrt(pow(triangleNormal.getX(), 2) + pow(triangleNormal.getY(), 2) + pow(triangleNormal.getZ(), 2)) *
				sqrt(pow(cameraNormal.getX(), 2) + pow(cameraNormal.getY(), 2) + pow(cameraNormal.getZ(), 2)));
		const auto Sp = S * cosA;
		return k * Sp * fabs(scalar(cameraNormal, triangleNormal));
	}
	return 0;
}

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

	wrki = sqrt(pow((v1.y * v2.z - v1.z * v2.y), 2) + pow((v1.z * v2.x - v1.x * v2.z), 2) + pow((v1.x * v2.y - v1.y * v2.x), 2));
	const double n_x = (v1.y * v2.z - v1.z * v2.y) / wrki;
	const double n_y = (v1.z * v2.x - v1.x * v2.z) / wrki;
	const double n_z = (v1.x * v2.y - v1.y * v2.x) / wrki;

	return { n_x, n_y, n_z };
}