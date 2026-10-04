#include "EuropeanOption.hpp"
#include "AmericanOption.hpp"
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using namespace Mikita::Options;

map<string, EuropeanOption> createBatches();

std::vector<double> MeshVector(double start, double end, double h);

std::vector<double> PriceOverMesh(const Option& opt,
	const std::vector<double>& S_mesh);

std::vector<double> DeltaOverMesh(const EuropeanOption& opt,
    const std::vector<double>& S_mesh);

std::vector<std::vector<double>> PriceMatrix(
	const std::vector<std::vector<double>>& params,
	const std::string& optType,
	const std::string& out_type = "Price",
	const std::string& style = "European");

std::vector<std::vector<double>> BuildParamMatrix(
	const EuropeanOption& base,
	const std::vector<double>& mesh,
	const std::string& whichParam,
	double S0);

std::vector<std::vector<double>> BuildParamMatrix(
	const AmericanOption& base,
	const std::vector<double>& mesh,
	const std::string& whichParam,
	double S0);

int main ()
{
    // Extracting batches
	map<string, EuropeanOption> batches = createBatches();

	// Spot prices S for each batch 
	map<string, double> spots = {
		{"Batch 1", 60.0},
		{"Batch 2", 100.0},
		{"Batch 3", 5.0},
		{"Batch 4", 100.0}
	};

	// Part (a): Black-Scholes call and put prices
	cout << "=== Part (a): Black-Scholes prices ===\n";
    vector <vector <double>> price_matrix;
    int temp_count_itr = 0;

	for (map <string, EuropeanOption>::iterator it = batches.begin ();
            it != batches.end (); ++it)
	{
		const string& name = (*it).first;
		EuropeanOption call = (*it).second;
		EuropeanOption put = (*it).second;
		put.toggle();

        vector <double> batch_price = {call.Price(spots[name]), put.Price(spots[name])};

        price_matrix.push_back (batch_price);

		cout << name << '\n'
		     << "  Call: " << price_matrix [temp_count_itr][0] << '\n'
		     << "  Put:  " << price_matrix [temp_count_itr][1]<< '\n';

        temp_count_itr++;
	}

	//  put-call parity, compute opposite price
	cout << "\n=== Part (b): Put-call parity ===\n";
    temp_count_itr = 0;

	for (map <string, EuropeanOption>::iterator it = batches.begin ();
        it != batches.end (); ++it)
	{
		const string& name = (*it).first;
		const EuropeanOption& option = (*it).second;
		const double S = spots[name];

		const double bsCall = price_matrix[temp_count_itr][0];
		const double bsPut  = price_matrix[temp_count_itr][1];

		const double putFromParity  = option.PutFromCallParity(bsCall, S);
		const double callFromParity = option.CallFromPutParity(bsPut, S);

		const bool parityHolds = option.CheckParity(bsCall, bsPut, S);

		cout << name << '\n'
		     << "  Put from call (parity):  " << putFromParity
		     << "  (BS put:  " << bsPut << ")\n"
		     << "  Call from put (parity):  " << callFromParity
		     << "  (BS call: " << bsCall << ")\n"
		     << "  CheckParity: " << (parityHolds ? "PASS" : "FAIL") << '\n';

		temp_count_itr++;
	}

	// Part C
	cout << "\n=== Part (c): Call prices vs S mesh (Batch 1) ===\n";
	const EuropeanOption& batch1 = batches["Batch 1"];
	vector<double> S_mesh = MeshVector(10.0, 50.0, 1.0);
	vector<double> prices_vs_S = PriceOverMesh(batch1, S_mesh);

	cout << "  (showing  " << S_mesh.size() << " points)\n";
	for (size_t i = 0; i < S_mesh.size(); ++i)
	{
		cout << "  S = " << S_mesh[i] << "  Call = " << prices_vs_S[i] << '\n';
	}

	// Part (d)

	cout << "\n=== Part (d): Price matrix vs T mesh (Batch 1) ===\n";
	vector<double> T_mesh = MeshVector(0.25, 1.0, 0.25);
	vector<vector<double>> T_params =
		BuildParamMatrix(batch1, T_mesh, "T", spots["Batch 1"]);
	vector<vector<double>> T_prices = PriceMatrix(T_params, "C", "Price");

	for (size_t i = 0; i < T_mesh.size(); ++i)
	{
		cout << "  T = " << T_mesh[i]
		     << "  Call = " << T_prices[i][0] << '\n';
	}

	cout << "\n=== Part (d): Price matrix vs sig mesh (Batch 1) ===\n";
	vector<double> sig_mesh = MeshVector(0.10, 0.50, 0.10);
	vector<vector<double>> sig_params =
		BuildParamMatrix(batch1, sig_mesh, "sig", spots["Batch 1"]);
	vector<vector<double>> sig_prices = PriceMatrix(sig_params, "C", "Price");

	for (size_t i = 0; i < sig_mesh.size(); ++i)
	{
		cout << "  sig = " << sig_mesh[i]
		     << "  Call = " << sig_prices[i][0] << '\n';
	}


    cout << "\n=== Part A2 (a) ===\n";

    EuropeanOption gamma_delta_test (0.1, 0.36, 100, 0.5, 0, "C", "Stock" );
    cout << "Delta Value Call: " << gamma_delta_test.Delta (105) << endl;
    gamma_delta_test.toggle ();
    cout << "Delta Value Put: " << gamma_delta_test.Delta (105) << endl;
    cout << "Gamma Value Call/Put: " << gamma_delta_test.Gamma (105) << endl;

    cout << "\n=== Part A2 (b) ===\n";
    
    gamma_delta_test.toggle();
    vector<double> delta_prices = MeshVector (10, 50, 1);
    vector<double> deltas_mesh = DeltaOverMesh (gamma_delta_test, delta_prices);

    temp_count_itr = 0;
    for (vector<double>::const_iterator it = deltas_mesh.begin(); 
        it != deltas_mesh.end();
        it++){
            cout << "Delta at Price " << delta_prices[temp_count_itr] 
                << " is " << deltas_mesh[temp_count_itr] << endl;
        temp_count_itr++;
        }

    cout << "\n=== Part A2 (c) ===\n";

    vector<vector<double>> greek_params =
        BuildParamMatrix(gamma_delta_test, MeshVector(95, 115, 5), "S", 105);
    vector<vector<double>> deltas = PriceMatrix(greek_params, "C", "Delta");
    vector<vector<double>> gammas = PriceMatrix(greek_params, "C", "Gamma");

    for (size_t i = 0; i < greek_params.size(); ++i)
        cout << "  S = " << greek_params[i][5]
             << "  Delta = " << deltas[i][0]
             << "  Gamma = " << gammas[i][0] << '\n';

     cout << "\n=== Part A2 (d) ===\n";

    // Generating h values

    vector <double> h = MeshVector(0.1, 3, 0.5);

    // Comparing Delta at different vlaues of h

    cout << "<<Delta Difference at S = 105>>"<< endl;
    double S = 105;
    for (double value : h){
        double exact_delta = gamma_delta_test.Delta (S);
        double num_delta = gamma_delta_test.Delta (S, "approximation", value);

        cout << "Exact Delta: " << exact_delta << endl 
        << "Numerical Delta: " << num_delta <<endl
        << "Difference between Exact and Numerical Delta at h = " << value << ": " << exact_delta - num_delta
        << endl <<endl;;
    }


    cout << "<<Gamma Difference at S = 105>>"<< endl;
    for (double value : h){
        double exact_gamma = gamma_delta_test.Gamma (S);
        double num_gamma = gamma_delta_test.Gamma (S, "approximation", value);

        cout << "Exact Gamma: " << exact_gamma << endl 
        << "Numerical Gamma: " << num_gamma <<endl
        << "Difference between Exact and Numerical Gamma at h = " << value << ": " << exact_gamma - num_gamma
        << endl <<endl;;
    }
    cout << "\n=== Part B (a) ===\n";

    cout << "AmericanOption class was added to implement formulae" <<endl;

    cout << "\n=== Part B (b) ===\n";

    AmericanOption test_American_option = AmericanOption (0.1, 0.1, 100, 0.02, "C");
    cout << "American Call Price: " << test_American_option.Price (110) << endl;
    test_American_option.toggle();
    cout << "American Put Price: " << test_American_option.Price (110) << endl;

    cout << endl;

    cout << "\n=== Part B (c) ===\n";

    //Generating S values using global function 

    vector <double> american_s =  MeshVector(70, 120, 1);

    test_American_option.toggle ();
    vector <double> american_p = PriceOverMesh(test_American_option, american_s);

    temp_count_itr = 0;
    for (vector<double>::const_iterator it = american_p.begin (); it != american_p.end (); it++){
        cout<< "American Call value at S = " << american_s[temp_count_itr] << ": " << *it << endl;
        temp_count_itr++;
    }

    cout << "\n=== Part B (d) ===\n";

    
    
	return 0;
}
