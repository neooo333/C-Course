#include "AmericanOption.hpp"
#include "Option.hpp"
#include <cmath>
#include <stdexcept>

using namespace std;

namespace Mikita {
    namespace Options {


        //################### Helpers ##################

        double AmericanOption::y () const {

            double variance = m_sig * m_sig;

            double first_part = 0.5 - m_b/ variance;
            double second_part = m_b/variance - 0.5;
            double third_part = sqrt (second_part * second_part + 2 * m_r / variance);

            if (m_optType == "C"){
                return first_part + third_part;
            } else if (m_optType == "P"){
                return first_part - third_part;
            } else {
                throw invalid_argument ("Invlaid Option Type");
            }

        }

        //##############################################

        AmericanOption::AmericanOption () : Option () {};

        AmericanOption::AmericanOption (double r_value, 
            double sig_value,
            double K_value, 
            double b_value,
            string option_type) 
            : Option (r_value, sig_value, K_value, b_value, option_type) {};


        AmericanOption::AmericanOption (const AmericanOption& o): Option(o){};

        AmericanOption& AmericanOption::operator = (const AmericanOption& o){

            if (this == &o) return *this;
            
            copy (o);
            return *this;
        }

        double AmericanOption::Price (double U) const {

            double y_value = y ();
            double second_multiplier = (y_value - 1) / y_value * U / m_K;

            if (m_optType == "C"){
                double first_multiplier = m_K / (y_value - 1);
                return first_multiplier * pow(second_multiplier, y_value);
            }else if (m_optType == "P"){
                double first_multiplier = m_K / (1 - y_value);
                return first_multiplier * pow(second_multiplier, y_value);
            } else {
                throw invalid_argument ("Invlaid Option Type");
            }

        }

        





    }
}