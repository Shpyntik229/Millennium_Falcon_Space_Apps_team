// albedo.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include <string>

using namespace std;

// TODO: Это пример библиотечной функции.
string albedo_to_information_of_material(float alb) {
	int albs = alb * 100;
	switch (albs)
	{
	case 4: //class P,D

		break;
	case 5: //class C,F
		return "Some C-class asteroids are known to have hydrated minerals on their surfaces or it is F-class where surface constituents anhydrous silicates, hydrated clay minerals, organic polymers, magnetite, and sulfides";
		break;
	case 8: //class T
		return "T-class asteroids may contain a large fraction of carbon polymers or organic-rich silicates or both in their surface material.";
		break;
	case 9: //class G
		return "G-class asteroid, probably has water present as a layer of permafrost. ";
		break;
	case 12: //class K
		return "K-class asteroids have spectral reflectances similar to the stony iron meteorites, and they are known to contain significant amounts of silicates and metals, including the minerals olivine and pyroxene on their surfaces.";
		break;
	case 14: //class B,M
		return "M-class asteroids may have significant amounts of nickel-iron metal in their surface material, and exhibit spectral reflectances similar to the nickel-iron meteorites or it is B-class where surface constituents is anhydrous silicates, hydrated clay minerals, organic polymers, magnetite, and sulfides.";
		break;
	case 18: //class S
		return "S-class asteroids have spectral reflectances similar to the stony iron meteorites, and they are known to contain significant amounts of silicates and metals, including the minerals olivine and pyroxene on their surfaces.";
		break;
	case 21: //class Q
		return "Q-class in the spectrum has features that indicate the presence of a metal.";
		break;
	case 34: //class V
		return "V-class asteroids are composed of stone iron, common chondrites and pyroxene";
		break;
	case 35: //class R
		return "R-class asteroids contain olivine and pyroxene.";
		break;
	case 42: //class A
		return "A-class asteroids contain high-temperature olivines or mixtures of olivine with metals, mainly iron and nickel.";
		break;
	case 44: //class E
		return "E-class asteroids contain high-temperature olivines or mixtures of olivine with metals, mainly iron and nickel.";
		break;
	default:
		return "Unknown asteroids material";
		break;
	}
}
