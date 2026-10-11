#include "OptionMesh.hpp"
#include <cmath>
#include <stdexcept>

std::vector<double> MeshVector(double start, double end, double h)
{
	if (h <= 0.0 || end < start)
		throw std::invalid_argument("MeshVector requires h > 0 and end >= start");

	const std::size_t num_points =
		static_cast<std::size_t>(std::floor((end - start) / h + 1.0e-9)) + 1;

	std::vector<double> mesh;
	mesh.reserve(num_points);
	for (std::size_t i = 0; i < num_points; ++i)
		mesh.push_back(start + i * h);

	return mesh;
}

std::vector<double> PriceOverMesh(const Mikita::Options::Option& option,
	const std::vector<double>& S_mesh)
{
	std::vector<double> prices;
	prices.reserve(S_mesh.size());
	for (std::size_t i = 0; i < S_mesh.size(); ++i)
		prices.push_back(option.Price(S_mesh[i]));

	return prices;
}
