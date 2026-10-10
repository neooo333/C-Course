// EuropeanOption.hpp
//
// European option priced with the generalised Black-Scholes formula
// (cost of carry b). Provides call/put prices, exact and divided-difference
// Greeks (delta, gamma) and put-call parity helpers.

#ifndef EuropeanOption_hpp
#define EuropeanOption_hpp


#include <string>
#include "Option.hpp"


namespace Mikita {
	namespace Options {

		class EuropeanOption : public Option{

		private:	
			// Attributes of the object (m_ prefix so accessors can reuse the names)
			double m_T;		// Expiry date
			std::string m_unam;	// Name of underlying asset


			// Private functions
			void copy(const EuropeanOption& o2);

			// Black-Scholes helper 
			double d1(double U) const;
			double d2(double U) const;

			// functions for option calculations
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
				const std::string& option_type,
				const std::string& asset_name); // Custom Constructor

			virtual ~EuropeanOption();	

			EuropeanOption& operator = (const EuropeanOption& option2);

			// Getters and Setters for private members

			const double& T() const { return m_T; }
			void T(double T_value) { m_T = T_value; }

			const std::string& unam() const { return m_unam; }
			void unam(const std::string& asset_name) { m_unam = asset_name; }

			// Functions that calculate option price and sensitivities
			double Price(double U) const;


			// Put-call parity
			double PutFromCallParity(double callPrice, double U) const;
			double CallFromPutParity(double putPrice, double U) const;
			bool CheckParity(double callPrice, double putPrice, double U,
				double tolerance = 1.0e-9) const;

			// Greeks 

			double Delta(double U) const;
			double Gamma (double U) const;

			// method: "exact" or "approximation" (central divided difference, step h)
			double Delta (double U, const std::string& method, double h = 0.01) const;
			double Gamma (double U, const std::string& method, double h = 0.01) const;

		};
	}
}



#endif
