#include "UI.h"
#include "SimulateRotation.h"
#include "Parser.h"
#include <iostream>
#include "matplotlibcpp.h"


int main(int argc, char* argv[]) {
	try {
		Input in(argc, argv);
		auto map = SimulateRotation(Parse(in.inputFile), 2 * PI / 360, in.albedo, in.lightVector, in.axisVector);
		std::vector<double> angs, lghts;
		for (auto& [key, val] : map) {
			std::cout << key << ' ' << val << std::endl;
			angs.push_back(key);
			lghts.push_back(val);
		}

		matplotlibcpp::plot(angs, lghts);
		matplotlibcpp::title("Light curve");
		matplotlibcpp::save(in.outputFile);
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}