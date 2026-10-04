#ifndef OPTION
#define OPTION

#include <string>

using namespace std;

namespace Mikita {
    namespace Options{
        // Abstract Class
        class Option {

            private:
                int id; //random id


            protected:
                double m_r;     // Interest rate
                double m_sig;	// Volatility
                double m_K;		// Strike price
                double m_b;		// Cost of carry
                string m_optType;	// Option name (call, put)

                // internal functions
                void copy (const Option& option_instance);

            public:
                // Constructors & Destructors
                Option ();
                Option (double r_value ,double sig_value, double K_value, double b_value, string option_type);
                Option (const Option& option_instance);

                virtual ~Option () {};

                // Operators
                Option& operator = (const Option& option_instance);


                // Getters and Setters

                const double& r() const { return m_r; }
                void r(double r_value) { m_r = r_value; }

                const double& sig() const { return m_sig; }
                void sig(double sig_value) { m_sig = sig_value; }
                const double& K() const { return m_K; }
                void K(double K_value) { m_K = K_value; }

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

			    void toggle();		// Change option type (C/P, P/C)


                //Pricing
                virtual double Price (double U) const = 0;
        };


    }
}





#endif