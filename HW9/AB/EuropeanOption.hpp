// EuropeanOption.hpp
//
// Class that represents  solutions to European options. This is
// an implementation using basic C++ syntax only.
//
// (C) Datasim Component Technology BV 2003-2011
//

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
using namespace std;

class EuropeanOption
{
private:	

	// Attributes of the object (m_ prefix so accessors can reuse the names)
	double m_r;		// Interest rate
	double m_sig;	// Volatility
	double m_K;		// Strike price
	double m_T;		// Expiry date
	double m_b;		// Cost of carry

	string m_optType;	// Option name (call, put)
	string m_unam;	// Name of underlying asset


	// Private functions
	void init();	// Initialise all default values
	void copy(const EuropeanOption& o2);

	// Black-Scholes helper 
	double d1(double U) const;
	double d2(double U) const;

	// 'Kernel' functions for option calculations
	double CallPrice(double U) const;
	double PutPrice(double U) const;
	double CallDelta(double U) const;
	double PutDelta(double U) const;
	

	// Gaussian functions
	double n(double x) const;
	double N(double x) const;

public:	// Public functions
	EuropeanOption();							// Default call option
	EuropeanOption(const EuropeanOption& option2);	// Copy constructor
	EuropeanOption(double r_value, 
		double sig_value,
		double K_value, 
		double T_value,
		double b_value,
		string option_type,
		string asset_name); // Custom Constructor

	EuropeanOption (const string& optionType);	// Create option type
	virtual ~EuropeanOption();	

	EuropeanOption& operator = (const EuropeanOption& option2);

	// Getters and Setters for private members
	const double& r() const { return m_r; }
	void r(double r_value) { m_r = r_value; }

	const double& sig() const { return m_sig; }
	void sig(double sig_value) { m_sig = sig_value; }
	const double& K() const { return m_K; }
	void K(double K_value) { m_K = K_value; }

	const double& T() const { return m_T; }
	void T(double T_value) { m_T = T_value; }

	const double& b() const { return m_b; }
	void b(double b_value) { m_b = b_value; }

	const string& optType() const { return m_optType; }
	void optType(const string& option_type)
	{
		m_optType = option_type;
		if (m_optType == "c")
			m_optType = "C";
		else if (m_optType == "p")
			m_optType = "P";
	}

	const string& unam() const { return m_unam; }
	void unam(const string& asset_name) { m_unam = asset_name; }



	// Functions that calculate option price and sensitivities
	double Price(double U) const;


	// Put-call parity
	double PutFromCallParity(double callPrice, double U) const;
	double CallFromPutParity(double putPrice, double U) const;
	bool CheckParity(double callPrice, double putPrice, double U,
		double tolerance = 1.0e-9) const;

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)


	// Greeks 

	double Delta(double U) const;
	double Gamma (double U) const;

	double Delta (double U, string method, double h = 0.01) const;
	double Gamma (double U, string method, double h = 0.01) const;




};

#endif
