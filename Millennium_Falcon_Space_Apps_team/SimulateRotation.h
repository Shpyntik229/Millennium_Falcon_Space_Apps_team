#pragma once
#include <map>
#include "MathCore.h"

std::map<double, double> SimulateRotation(Mesh i_mesh, double i_accuracy_deg, double k, const Point3D& lightNormal,
	const Point3D& center, const Point3D& axisAng);