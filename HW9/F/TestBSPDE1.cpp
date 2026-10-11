// TestBSPDE1.cpp
//
// Testing 1 factor BS model — Explicit Euler FDM (European puts).
// Batches 1–4: exact vs FDM put price.
//
// (C) Datasim Education BV 2005-2011
//

#include "FDMDirector.hpp"

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

namespace BS // Black Scholes
{
	double sig = 0.3;
	double K = 65.0;
	double T = 0.25;
	double r = 0.08;
	double D = 0.0; // aka q

	double mySigma(double x, double /*t*/)
	{
		double sigmaS = sig * sig;
		return 0.5 * sigmaS * x * x;
	}

	double myMu(double x, double /*t*/)
	{
		return (r - D) * x;
	}

	double myB(double /*x*/, double /*t*/)
	{
		return -r;
	}

	double myF(double /*x*/, double /*t*/)
	{
		return 0.0;
	}

	double myBCL(double t)
	{
		// Put
		return K * exp(-r * t);
	}

	double myBCR(double /*t*/)
	{
		// Put
		return 0.0; // P
	}

	double myIC(double x)
	{
		// Put
		return max(K - x, 0.0);
	}
}

int main()
{
	using namespace ParabolicIBVP;

	// Assignment of functions
	sigma = BS::mySigma;
	mu = BS::myMu;
	b = BS::myB;
	f = BS::myF;
	BCL = BS::myBCL;
	BCR = BS::myBCR;
	IC = BS::myIC;

	// Batches 1–4: T, K, sig, r, S, exact put
	const double batchT[]   = { 0.25, 1.0, 1.0, 30.0 };
	const double batchK[]   = { 65.0, 100.0, 10.0, 100.0 };
	const double batchSig[] = { 0.30, 0.20, 0.50, 0.30 };
	const double batchR[]   = { 0.08, 0.0, 0.12, 0.08 };
	const double batchS[]   = { 60.0, 100.0, 5.0, 100.0 };
	const double exactPut[] = { 5.84628, 7.96557, 4.07326, 1.24750 };


	for (int b = 0; b < 4; ++b)
	{
		BS::T = batchT[b];
		BS::K = batchK[b];
		BS::sig = batchSig[b];
		BS::r = batchR[b];
		BS::D = 0.0;

		int J = static_cast<int>(5 * BS::K);
		int N = J * J; // k = O(h^2) !!!!!!!!!
		double Smax = 5 * BS::K; // Magix

		// Batch 4 (T=30): coarser J + larger N doesnt  stays stable
		if (b == 3)
		{
			J = 100;
			N = 50000;
		}

		FDMDirector fdir(Smax, BS::T, J, N);
		fdir.doit();

		// Spot S is on the mesh for these batches: index i with x[i] = S
		const double h = Smax / J;
		const size_t i = static_cast<size_t>(batchS[b] / h + 0.5);
		const double fdmP = fdir.current()[i];
		const double exact = exactPut[b];
		cout << "Batch " << (b + 1)
			<< "  Exact=" << exact
			<< "  FDM=" << fdmP
			<< "  |diff|=" << fabs(fdmP - exact) << "\n";
	}

	return 0;
}
