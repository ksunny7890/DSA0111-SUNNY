#include <array>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };
constexpr array<long long, 4> FARE_PAISE = {1000, 2000, 3000, 6000};

long long calculateFare(Zone zone, bool peak, bool weekend) {
    long long amount = FARE_PAISE.at(static_cast<int>(zone));

    // Assumption: weekend discount takes precedence and is not combined with peak surcharge.
    if (weekend) {
        amount = amount * 90 / 100;
    } else if (peak) {
        amount = amount * 120 / 100;
    }
    return amount;
}

int main() {
    cout << "Airport weekday peak: "
         << calculateFare(Zone::Airport, true, false) << " paise\n";
    cout << "Airport weekend: "
         << calculateFare(Zone::Airport, false, true) << " paise\n";
    cout << "Outer weekend: "
         << calculateFare(Zone::Outer, false, true) << " paise\n";
    return 0;
}
