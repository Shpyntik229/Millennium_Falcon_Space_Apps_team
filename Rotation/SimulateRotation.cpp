#include <cmath>
#include <map>
#include "MathCore.h"

inline void RotatePointOX(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	point.y = point.y * cos(deg) - point.z * sin(deg);
	point.z = point.y * sin(deg) + point.z * cos(deg);
	point = point + center;
}

inline void RotatePointOY(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	point.x = point.x * cos(deg) + point.z * sin(deg);
	point.z = -point.x * sin(deg) + point.z * cos(deg);
	point = point + center;
}

inline void RotatePointOZ(Point3D& point, double deg, const Point3D center)
{
	point = point - center;
	point.x = point.x * cos(deg) - point.y * sin(deg);
	point.y = point.x * sin(deg) + point.y * cos(deg);
	point = point + center;
}

void RotateMesh(Mesh& mesh, double deg, const Point3D& center, const Point3D& axisAng)
{
	
	for (auto& vert : mesh.getVertices())
	{
		double angXY = std::acos(getAngle({ 1, 0 }, { axisAng.x, axisAng.y })) *
			(cross_mult(Point2D{ axisAng.x, axisAng.y }, { 1, 0 }) < 0 ? -1 : 1);
		RotatePointOZ(vert, angXY, center);
		double angXZ = std::acos(getAngle({ 0, 1 }, { axisAng.x, axisAng.z }) *
			(cross_mult(Point2D{ axisAng.x, axisAng.z }, { 0, 1 }) < 0 ? -1 : 1));
		RotatePointOY(vert, angXZ, center);

		RotatePointOZ(vert, deg, center);

		RotatePointOY(vert, -angXZ, center);
		RotatePointOZ(vert, -angXY, center);
	}
}

std::map<double, double> SimulateRotation(Mesh i_mesh, double i_accuracy_deg, const Point3D& center, const Point3D& axisAng)
{
	for (double deg = 0; deg < 2 * PI; deg += i_accuracy_deg)
	{
		RotateMesh(i_mesh, deg, center, axisAng);

	}
	return {};
}