// TestNormal.cpp
//
// First program test the Boost statistics library.
//
// Look at the Normal distribution because it is important.
// And gamma distribution
//
// 2008-6-27 DD initial code
// 2011-11-9 DD for QN course
//
// (C) Datasim Education BV 2009-2011
//

#include <boost/math/distributions/exponential.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions.hpp> // For non-member functions of distributions

#include <vector>
#include <iostream>
using namespace std;


int main()
{
	// Don't forget to tell compiler which namespace
	using namespace boost::math;

	exponential_distribution<> myExpo(2.0); // Default type is 'double'
	cout << "Mean: " << mean(myExpo) << ", standard deviation: " << standard_deviation(myExpo) << endl;

	// Distributional properties
	double x = 3.24;

	cout << "pdf: " << pdf(myExpo, x) << endl;
	cout << "cdf: " << cdf(myExpo, x) << endl;

	// Default is lambda = 1
	exponential_distribution<float> myExpo2; 
	cout << "Mean: " << mean(myExpo2) << ", standard deviation: " << standard_deviation(myExpo2) << endl;
	
	cout << "pdf: " << pdf(myExpo2, x) << endl;
	cout << "cdf: " << cdf(myExpo2, x) << endl;

	// Choose precision
	cout.precision(10); // Number of values behind the comma

	// Other properties
	cout << "\n***exponential distribution: \n";
	cout << "mean: " << mean(myExpo) << endl;
	cout << "variance: " << variance(myExpo) << endl;
	cout << "median: " << median(myExpo) << endl;
	cout << "mode: " << mode(myExpo) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExpo) << endl;
	cout << "kurtosis: " << kurtosis(myExpo) << endl;
	cout << "characteristic function: " << chf(myExpo, x) << endl;
	cout << "hazard: " << hazard(myExpo, x) << endl;


	// Poisson distribution
	int lamb = 5;
	poisson_distribution<float> myPoisson(lamb);

	int val = 13.0;
	cout << endl <<  "pdf: " << pdf(myPoisson, val) << endl;
	cout << "cdf: " << cdf(myPoisson, val) << endl;

	vector<double> pdfList;
	vector<double> cdfList;

	int start = 0;
	int end = 10;


	for (long j = start; j <= end; ++j)
	{
		pdfList.push_back(pdf(myPoisson, j));
		cdfList.push_back(cdf(myPoisson, j));
	}

	for (long j = 0; j < pdfList.size(); ++j)
	{
		cout << pdfList[j] << ", ";

	}

	cout << "***" << endl;

	for (long j = 0; j < cdfList.size(); ++j)
	{
		cout << cdfList[j] << ", ";

	}

	return 0;
}