#pragma once
#include <string>

struct Input {
    Input(int argc, char* argv[]);

    std::string link3d = "";
    int speed = 0;
};