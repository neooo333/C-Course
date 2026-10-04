#include "Option.hpp"
#include <string>
#include <cstdlib>

using namespace std;


namespace Mikita{
    namespace Options {

        Option::Option () 
            : id (rand ()), m_r (0.05), m_sig (0.2), m_K (110.0), m_b (0.05), m_optType ("C")
            {}

        Option::Option (double r_value ,double sig_value, double K_value, double b_value, string option_type)
            : id (rand ()), m_r (r_value), m_sig (sig_value), m_K (K_value), 
            m_b (b_value),  m_optType (option_type) {}

        
        void Option::copy (const Option& option_instance) {
            id = option_instance.id;
            m_r = option_instance.m_r;
            m_sig = option_instance.m_sig;
            m_K = option_instance.m_K;
            m_b = option_instance.m_b;
            m_optType = option_instance.m_optType;
        }
        
        Option::Option (const Option& option_instance){

            Option::copy (option_instance);
        }

        Option& Option::operator = (const Option& option_instance){
            if (this == &option_instance){
                return *this;
            }

            Option::copy (option_instance);

            return *this;
        }

        		// Modifier functions
		void Option::toggle()
		{ // Change option type (C/P, P/C)

			if (m_optType == "C")
				m_optType = "P";
			else
				m_optType = "C";
		}



        





    }
}
