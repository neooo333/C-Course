// EuropeanOption.cpp
//
// Implementation of the generalised Black-Scholes European option
// (formulae as given in the Level 9 assignment, after Haug).


#include "EuropeanOption.hpp"
#include "Option.hpp"
#include <cmath>
#include <stdexcept>
#include <string>
#include <boost/math/distributions/normal.hpp>

using namespace std;


namespace Mikita {
	namespace Options{
		//////////// Gaussian functions /////////////////////////////////
		double EuropeanOption::n(double x) const
		{ 

			boost::math::normal_distribution<> standardNormal;
			return boost::math::pdf (standardNormal, x);
		}

		double EuropeanOption::N(double x) const
		{ // Standard normal CDF via Boost.Math

			boost::math::normal_distribution<> standardNormal;	// mean 0, sd 1
			return boost::math::cdf(standardNormal, x);
		}


		// Black-Scholes helper
		double EuropeanOption::d1(double U) const
		{
			return ( log(U/m_K) + (m_b + (m_sig*m_sig)*0.5) * m_T ) / (m_sig * sqrt(m_T));
		}

		double EuropeanOption::d2(double U) const
		{
			return d1(U) - m_sig * sqrt(m_T);
		}


		// Kernel Functions (Haug)
		double EuropeanOption::CallPrice(double U) const
		{
			return (U * exp((m_b-m_r)*m_T) * N(d1(U))) - (m_K * exp(-m_r * m_T) * N(d2(U)));
		}

		double EuropeanOption::PutPrice(double U) const
		{
			return (m_K * exp(-m_r * m_T) * N(-d2(U))) - (U * exp((m_b-m_r)*m_T) * N(-d1(U)));
		}

		double EuropeanOption::CallDelta(double U) const
		{
			return exp((m_b-m_r)*m_T) * N(d1(U));
		}

		double EuropeanOption::PutDelta(double U) const
		{
			return exp((m_b-m_r)*m_T) * (N(d1(U)) - 1.0);
		}



		/////////////////////////////////////////////////////////////////////////////////////


		void EuropeanOption::copy( const EuropeanOption& o2)
		{

			Option::copy (o2);
			m_T	= o2.m_T;
			m_unam = o2.m_unam;
			
		}

		EuropeanOption::EuropeanOption() : Option(), m_T(0.5), m_unam("Stock") {}

		EuropeanOption::EuropeanOption(const EuropeanOption& o2)
			: Option(o2), m_T(o2.m_T), m_unam(o2.m_unam)
		{}

		EuropeanOption::EuropeanOption(double r_value,
			double sig_value,
			double K_value,
			double T_value,
			double b_value,
			const string& option_type,
			const string& asset_name)
			: Option(r_value, sig_value, K_value, b_value, option_type),
			  m_T(T_value), m_unam(asset_name)
		{}


		EuropeanOption::~EuropeanOption()
		{}


		EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
		{

			if (this == &option2) return *this;

			copy (option2);

			return *this;
		}

		// Functions that calculate option price and sensitivities
		double EuropeanOption::Price(double U) const
		{

			if (optType () == "C")
				return CallPrice(U);
			else
				return PutPrice(U);
		}	



		// Greeks ########################################
		double EuropeanOption::Delta(double U) const 
		{
			if (optType () == "C")
				return CallDelta(U);
			else
				return PutDelta(U);

		}

		double EuropeanOption::Gamma (double U) const{

			double numerator  = n(d1(U)) * exp((m_b - m_r) * m_T);
			double denominator = U * m_sig * sqrt(m_T);

			return numerator / denominator;
		}



		double EuropeanOption::Delta (double U, const string& method, double h) const{
			if (method == "approximation"){
				double numerator  = EuropeanOption::Price (U + h) - EuropeanOption::Price (U - h);
				double denominator = 2 * h;
				return numerator / denominator;
			}else if (method == "exact"){
				return EuropeanOption::Delta (U);
			}else {
				throw std::invalid_argument ("Invalid method");
			}
		}

		double EuropeanOption::Gamma (double U, const string& method, double h) const{
			if (method == "approximation"){
				double numerator  = EuropeanOption::Price (U + h) 
					+ EuropeanOption::Price (U - h)
					- 2 * EuropeanOption::Price (U);
				double denominator = h * h;
				return numerator / denominator;
			}else if (method == "exact"){
				return EuropeanOption::Gamma (U);
			}else {
				throw std::invalid_argument ("Invalid method");
			}
		}


		// ##################################################

		// Put-call parity helpers (independent of m_optType)
		double EuropeanOption::PutFromCallParity(double callPrice, double U) const
		{
			return callPrice + m_K * exp(-m_r * m_T) - U * exp((m_b - m_r) * m_T);
		}

		double EuropeanOption::CallFromPutParity(double putPrice, double U) const
		{
			return putPrice - m_K * exp(-m_r * m_T) + U * exp((m_b - m_r) * m_T);
		}

		bool EuropeanOption::CheckParity(double callPrice, double putPrice, double U,
			double tolerance) const
		{	// C + K exp(-rT) == P + U exp((b-r)T)

			double lhs = callPrice + m_K * exp(-m_r * m_T);
			double rhs = putPrice + U * exp((m_b - m_r) * m_T);

			return fabs(lhs - rhs) < tolerance;
		}


	}
}




