#pragma once
#include <vector>
#include "Triangle.h"
#include "Vertex.h"

using TriangleMesh = std::pair<std::vector<Vertex>, std::vector<Triangle>>;
TriangleMesh Parse(const char* filename);