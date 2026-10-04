#ifndef AMERICAN
#define AMERICAN

#include "Option.hpp"

namespace Mikita{
    namespace Options {

        class AmericanOption : public Option {

            private:

                //helpers
                double y () const;

            public:

                AmericanOption ();
                AmericanOption (double r_value, 
                    double sig_value,
                    double K_value, 
                    double b_value,
                    string option_type);
                
                virtual ~AmericanOption () {};

                AmericanOption (const AmericanOption& o);

                AmericanOption& operator = (const AmericanOption& o);

                //Price
                double Price (double U) const;
        };

    }
}



#endif