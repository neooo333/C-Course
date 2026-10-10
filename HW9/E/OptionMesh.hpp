#ifndef OptionMesh_hpp
#define OptionMesh_hpp

#include "Option.hpp"
#include <vector>

std::vector<double> MeshVector(double start, double end, double h);
std::vector<double> PriceOverMesh(const Mikita::Options::Option& option,
	const std::vector<double>& S_mesh);

#endif
