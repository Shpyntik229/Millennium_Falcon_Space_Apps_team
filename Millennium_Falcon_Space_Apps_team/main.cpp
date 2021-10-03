#include "UI.h"
#include "SimulateRotation.h"
#include "Parser.h"
#include <iostream>
#include "matplotlibcpp.h"


int main() {
	auto map = SimulateRotation(Parse("potato.obj"), 2 * PI / 360, 1, { 0, 1, 0 }, { 0, 0, 0 }, { 0, 1, 0 });
	std::vector<double> angs, lghts;
	for (auto& [key, val] : map) {
		std::cout << key << ' ' << val << std::endl;
		angs.push_back(key);
		lghts.push_back(val);
	}

	matplotlibcpp::plot(angs, lghts);
	matplotlibcpp::title("Light curve");
	matplotlibcpp::save("grafic.png");
}