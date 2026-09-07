#include <boost/random.hpp>
#include <ctime>
#include <iostream>
#include <map>

using namespace std;

int main() {
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;
    // Set the seed.
    myRng.seed(static_cast<boost::uint32_t>(std::time(0)));
    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1, 6);

    map<int, long> statistics; // Structure to hold outcome + frequencies
    int outcome;
    long n;

    cout << "How many trials? ";
    cin >> n;
    cout << endl;

    for (long i = 0; i < n; ++i) {
        outcome = six(myRng);
        statistics[outcome] += 1;
    }

    cout << "How many Trials? " << int (n) <<endl;
    cout <<endl;
    cout << "Trial 1 has " << statistics [1] *100.0/ n<< "% outcomes" << endl;
    cout << "Trial 2 has " << statistics [2] *100.0/ n<< "% outcomes" << endl;
    cout << "Trial 3 has " << statistics [3] *100.0/ n<< "% outcomes" << endl;
    cout << "Trial 4 has " << statistics [4] *100.0/ n<< "% outcomes" << endl;
    cout << "Trial 5 has " << statistics [5] *100.0/ n<< "% outcomes" << endl;
    cout << "Trial 6 has " << statistics [6] *100.0/ n<< "% outcomes" << endl;

    return 0;
}
