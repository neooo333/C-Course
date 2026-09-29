
// A class that models a European option as an instance of an Entity object.
//
// (C) Datasim Component Technology BV 2003
//

#include "EuropeanOption.hpp"
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>


std::map<std::string, EuropeanOption> createBatches()
{
	return {
		{"Batch 1", EuropeanOption(0.08, 0.30, 65.0, 0.25, 0.08, "C", "Stock")},
		{"Batch 2", EuropeanOption(0.0, 0.2, 100.0, 1.0, 0.0, "C", "Stock")},
		{"Batch 3", EuropeanOption(0.12, 0.50, 10.0, 1.0, 0.12, "C", "Stock")},
		{"Batch 4", EuropeanOption(0.08, 0.30, 100.0, 30.0, 0.08, "C", "Stock")}
	};
}


std::vector<double> MeshVector(double start, double end, double h) {
    std::vector<double> mesh;
    
    size_t num_points = static_cast<size_t>(std::ceil((end - start) / h)) + 1;
    mesh.reserve(num_points);

    for (double x = start; x <= end + h * 0.5; x += h) {
        mesh.push_back(x);
    }

    return mesh;
}

// Price a fixed option at each spot in S_mesh.
std::vector<double> PriceOverMesh(const EuropeanOption& opt,
                                  const std::vector<double>& S_mesh)
{
	std::vector<double> prices;
	prices.reserve(S_mesh.size());
	for (std::size_t i = 0; i < S_mesh.size(); ++i)
		prices.push_back(opt.Price(S_mesh[i]));
	return prices;
}

std::vector<double> DeltaOverMesh(const EuropeanOption& opt,
	const std::vector<double>& S_mesh)
{
	std::vector<double> deltas;
	deltas.reserve(S_mesh.size());
	for (std::size_t i = 0; i < S_mesh.size(); ++i)
		deltas.push_back(opt.Delta(S_mesh[i]));
	return deltas;
}



// Each row of params: {r, sig, K, T, b, S}. Returns one price per row.
std::vector<std::vector<double>> PriceMatrix(
	const std::vector<std::vector<double>>& params,
	const std::string& optType,
	const std::string& out_type){

	double (EuropeanOption::*metric) (double) const;

	if (out_type =="Price"){
		metric = &EuropeanOption::Price;
	}else if (out_type == "Delta"){
		metric = &EuropeanOption::Delta;
	}else if (out_type == "Gamma"){
		metric = &EuropeanOption::Gamma;
	}else{
		throw std::invalid_argument ("Unknown out_type");
	}

	std::vector<std::vector<double>> metrics;
	metrics.reserve(params.size());

	for (std::size_t i = 0; i < params.size(); ++i){
		const std::vector<double>& row = params[i];
		EuropeanOption opt(row[0], row[1], row[2], row[3], row[4],
			optType, "Stock");
		metrics.push_back(std::vector<double>{(opt.*metric)(row[5])});
	}

	return metrics;
}

//Build a params matrix from a base option by sweeping one field over mesh.
// whichParam: "r", "sig", "K", "T", "b", or "S". S0 is the spot used when
// whichParam is not "S".
std::vector<std::vector<double>> BuildParamMatrix(
	const EuropeanOption& base,
	const std::vector<double>& mesh,
	const std::string& whichParam,
	double S0)
{
	std::vector<std::vector<double>> params;
	params.reserve(mesh.size());

	for (std::size_t i = 0; i < mesh.size(); ++i)
	{
		double r = base.r();
		double sig = base.sig();
		double K = base.K();
		double T = base.T();
		double b = base.b();
		double S = S0;

		if (whichParam == "r")
			r = mesh[i];
		else if (whichParam == "sig")
			sig = mesh[i];
		else if (whichParam == "K")
			K = mesh[i];
		else if (whichParam == "T")
			T = mesh[i];
		else if (whichParam == "b")
			b = mesh[i];
		else if (whichParam == "S")
			S = mesh[i];

		params.push_back(std::vector<double>{r, sig, K, T, b, S});
	}
	return params;
}


