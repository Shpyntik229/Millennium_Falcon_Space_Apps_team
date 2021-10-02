#include <sstream>
#include <iostream>

#include "UI.h"

using namespace std;

Input::Input(int argc, char* argv[]) {
    if (argc < 3) cout << "error input: " << argc - 1 << " arguments on start\n";
    else {
        istringstream ss(argv[1]);
        ss >> link3d;
        string ll = argv[2];
        if (ll.size() <= 8) {
            cout << "error input speed (small text)\n";
        }
        else {
            string t = "";
            for (int i = 0; i < 8; i++) {
                t += ll[i];
            }
            if (t != "--speed=")cout << "error input speed (unknown text)\n";
            else {
                string k = "";
                for (int i = 8; i < ll.size(); i++) {
                    k += ll[i];
                }
                istringstream sss(k);
                sss >> speed;
            }
        }
    }
}