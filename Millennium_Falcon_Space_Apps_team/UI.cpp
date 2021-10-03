#include <sstream>
#include <iostream>
#include <string_view>
#include <exception>

#include "UI.h"

using namespace std;

Input::Input(int argc, char* argv[]) {
    if (argc < 2) throw invalid_argument("There are no arguments, you need to add path to the model file!");
    else {
        inputFile = argv[1];
        for (int i = 2; i < argc; i++) {
            string_view arg = argv[i];
            arg.remove_prefix(1);
            size_t sign = arg.find('=');
            string_view name = arg.substr(0, sign);
            string_view value = arg.substr(sign+1);
            if (name == "o") {
                outputFile = value;
            }
            else if (name == "c") {
                c = stod(string(value));
            }
            else if (name == "l") {
                size_t comma = value.find_first_of(',');
                lightVector.x = stod(string(value.substr(0, comma)));
                value.remove_prefix(comma + 1);
                comma = value.find_first_of(',');
                lightVector.y = stod(string(value.substr(0, comma)));
                value.remove_prefix(comma + 1);
                lightVector.z = stod(string(value));
            }
            else if (name == "r") {
                size_t comma = value.find_first_of(',');
                axisVector.x = stod(string(value.substr(0, comma)));
                value.remove_prefix(comma + 1);
                comma = value.find_first_of(',');
                axisVector.y = stod(string(value.substr(0, comma)));
                value.remove_prefix(comma + 1);
                axisVector.z = stod(string(value));
            }
            else {
                cerr << "Invalid argument! " << name << " doesn't exist" << endl;
            }
        }
    }
}