#include "Parser.h"
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

Mesh Parse(const char* filename)
{
    std::vector<Point3D> vertices;
    std::vector<TriangleVertices> triangles;

    std::ifstream in(filename, std::ios::in);
    if (!in)
    {
        std::cerr << "Cannot open " << filename << std::endl;
        exit(1);

    }
    std::string line;
    while (std::getline(in, line))
    {
        if (line.substr(0, 2) == "v ") {
            std::istringstream v(line.substr(2));
            double x, y, z;
            v >> x; v >> y; v >> z;
            vertices.push_back({ x, y, z });
        }
        else if (line.substr(0, 2) == "f ") {
            std::size_t i1, i2, i3, i4;

            const char* chh = line.c_str();
            sscanf_s(chh, "f %llu/%*i/%*i %llu/%*i/%*i %llu/%*i/%*i %llu/%*i/%*i", &i1, &i2, &i3, &i4);

            i1--; i2--; i3--; i4--;

            triangles.push_back({ i1, i2, i3 });
            triangles.push_back({ i1, i3, i4 });
        }
    }
    return { std::move(vertices), std::move(triangles) };
}