#pragma once
#include <string>

#include "MathCore.h"

struct Input {
    Input(int argc, char* argv[]);

    std::string outputFile = "grafic.png";
    char* inputFile;
    Point3D lightVector = { 0, 1, 0 }, axisVector = {0, 0, 1};
    double albedo = 1;
    
};