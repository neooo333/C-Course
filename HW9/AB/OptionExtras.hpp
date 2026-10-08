
// Global helper functions that operate on options: test batches, mesh
// generation, pricing over a mesh and the matrix pricer.

#ifndef OptionExtras_hpp
#define OptionExtras_hpp

#include "AmericanOption.hpp"
#include "EuropeanOption.hpp"
#include "Option.hpp"
#include <map>
#include <string>
#include <vector>
// Batches 1-4 from the assignment (call options; spot prices are kept separately).
std::map<std::string, Mikita::Options::EuropeanOption> createBatches();

// Points start, start + h, ..., up to and including end.
std::vector<double> MeshVector(double start, double end, double h);

// Price of opt at every spot in S_mesh (works for any Option).
std::vector<double> PriceOverMesh(const Mikita::Options::Option& opt,
	const std::vector<double>& S_mesh);

// Exact delta of opt at every spot in S_mesh.
std::vector<double> DeltaOverMesh(const Mikita::Options::EuropeanOption& opt,
	const std::vector<double>& S_mesh);

// European rows: {r, sig, K, T, b, S}. American rows: {r, sig, K, b, S}.
// out_type: "Price", "Delta" or "Gamma"; style: "European" or "American".
// American only supports out_type "Price".
std::vector<std::vector<double>> PriceMatrix(
	const std::vector<std::vector<double>>& params,
	const std::string& optType,
	const std::string& out_type = "Price",
	const std::string& style = "European");
// Build a params matrix from a base option by sweeping one field over mesh.
// whichParam: "r", "sig", "K", "T", "b", or "S". S0 is the spot used when
// whichParam is not "S".
std::vector<std::vector<double>> BuildParamMatrix(
	const Mikita::Options::EuropeanOption& base,
	const std::vector<double>& mesh,
	const std::string& whichParam,
	double S0);

// American rows: {r, sig, K, b, S}. whichParam: "r", "sig", "K", "b", or "S".
std::vector<std::vector<double>> BuildParamMatrix(
	const Mikita::Options::AmericanOption& base,
	const std::vector<double>& mesh,
	const std::string& whichParam,
	double S0);

#endif
