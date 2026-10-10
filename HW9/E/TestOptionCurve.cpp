#include "ExcelDriverLite.hpp"
#include "EuropeanOption.hpp"
#include "OptionMesh.hpp"

#include <list>
#include <string>
#include <vector>

int main()
{
	const std::vector<double> S_mesh = MeshVector(10.0, 50.0, 1.0);

	Mikita::Options::EuropeanOption call(
		0.05, 0.20, 30.0, 1.0, 0.05, "C", "Stock");
	Mikita::Options::EuropeanOption put(call);
	put.toggle();

	const std::vector<double> call_prices = PriceOverMesh(call, S_mesh);
	const std::vector<double> put_prices = PriceOverMesh(put, S_mesh);

	std::list<std::string> labels;
	labels.push_back("Call");
	labels.push_back("Put");

	std::list<std::vector<double>> prices;
	prices.push_back(call_prices);
	prices.push_back(put_prices);

	ExcelDriver excel;
	excel.MakeVisible(true);
	excel.CreateChart(S_mesh, labels, prices,
		"European Option Prices vs Underlying Price", "Underlying Price S", "Option Price");

	//  open VS terminal
	// cd "C:\Users\nikit\OneDrive\Documents\C-Course\HW9\E"
	// cl /EHsc /std:c++14 /I. /I"C:\Users\nikit\boost\boost_1_82_0" /Fe:TestOptionCurve.exe TestOptionCurve.cpp Option.cpp EuropeanOption.cpp OptionMesh.cpp UtilitiesDJD\ExceptionClasses\DatasimException.cpp UtilitiesDJD\BitsAndPieces\StringConversions.cpp

	
	return 0;
}
