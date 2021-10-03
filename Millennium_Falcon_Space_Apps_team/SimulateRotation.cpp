#include <cmath>
#include "MathCore.h"
#include "SimulateRotation.h"

inline void RotatePointOX(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	double y = point.y * cos(deg) - point.z * sin(deg);
	double z = point.y * sin(deg) + point.z * cos(deg);
	point.y = y;
	point.z = z;
	point = point + center;
}

inline void RotatePointOY(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	double x = point.x * cos(deg) + point.z * sin(deg);
	double z = -point.x * sin(deg) + point.z * cos(deg);
	point.x = x;
	point.z = z;
	point = point + center;
}

inline void RotatePointOZ(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	double x = point.x * cos(deg) - point.y * sin(deg);
	double y = point.x * sin(deg) + point.y * cos(deg);
	point.x = x;
	point.y = y;
	point = point + center;
}

void RotateMesh(Mesh& mesh, double deg, const Point3D& center, const Point3D& axisAng)
{

	for (auto& vert : mesh.getVertices())
	{
		double angXY = getAngle(Point2D{ 1, 0 }, { axisAng.x, axisAng.y });
		if (cross_mult(Point2D{ axisAng.x, axisAng.y }, { 1, 0 }) < 0)
			angXY = 2 * PI - angXY;
		if (std::isnan(angXY))
			angXY = 0;
		RotatePointOZ(vert, angXY, center);
		double angXZ = getAngle(Point2D{ 0, 1 }, { axisAng.x, axisAng.z });
		if (cross_mult(Point2D{ axisAng.x, axisAng.z }, { 0, 1 }) < 0)
			angXZ = 2 * PI - angXZ;
		if (std::isnan(angXZ))
			angXZ = 0;
		RotatePointOY(vert, angXZ, center);

		RotatePointOZ(vert, deg, center);

		RotatePointOY(vert, -angXZ, center);
		RotatePointOZ(vert, -angXY, center);
	}
}

double MeshLight(Mesh& mesh, double k, const Point3D& lightNormal) {
	double res_light = 0;
	for (auto& triangle : mesh.getTriangles()) {
		auto& vertices = mesh.getVertices();
		res_light += CaclLight(vertices[triangle.a], vertices[triangle.b], vertices[triangle.c], k, lightNormal);
	}
	return res_light;
}

std::map<double, double> SimulateRotation(Mesh i_mesh, double i_accuracy_deg, double k, const Point3D& lightNormal, 
	const Point3D& center, const Point3D& axisAng)
{
	std::map<double, double> map;
	for (double deg = 0; deg < 2 * PI + i_accuracy_deg; deg += i_accuracy_deg)
	{
		map[deg] = MeshLight(i_mesh, k, lightNormal);
		RotateMesh(i_mesh, i_accuracy_deg, center, axisAng);
	}
	return map;
}