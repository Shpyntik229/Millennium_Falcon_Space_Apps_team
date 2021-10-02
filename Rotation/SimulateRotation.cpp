#include <cmath>
#include <map>
#include "MathCore.h"

inline void RotatePointOZ(Point3D& point, const Point3D center, double deg)
{
	point = point - center;
	point.x = point.x * cos(deg) - point.y * sin(deg);
	point.y = point.x * sin(deg) + point.y * cos(deg);
	point = point + center;
}

void RotateMesh(Mesh& mesh, Point3D center, double deg)
{
	for (auto& vert : mesh.getVertices())
	{
		RotatePointOZ(vert, center, deg);
	}
}

std::map<double, double> SimulateRotation(Mesh i_mesh, double i_accuracy_deg, Point3D center)
{
	for (double deg = 0; deg < 2 * PI; deg += i_accuracy_deg)
	{

		RotateMesh(i_mesh, center, deg);
	}
	return {};
}