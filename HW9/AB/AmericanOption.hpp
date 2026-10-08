// AmericanOption.hpp
//
// Perpetual American option (no expiry). Closed-form call and put prices.

#ifndef AmericanOption_hpp
#define AmericanOption_hpp

#include "Option.hpp"
#include <string>

namespace Mikita{
    namespace Options {

        class AmericanOption : public Option {

            private:

                //helpers
                double y () const;	// y1 for a call, y2 for a put

            public:

                AmericanOption ();
                AmericanOption (double r_value, 
                    double sig_value,
                    double K_value, 
                    double b_value,
                    const std::string& option_type);
                
                virtual ~AmericanOption () {};

                AmericanOption (const AmericanOption& o);

                AmericanOption& operator = (const AmericanOption& o);

                //Price
                double Price (double U) const;
        };

    }
}



#endif
