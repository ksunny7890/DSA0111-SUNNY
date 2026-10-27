#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    cout << "Inner fare (paise): " << INNER_FARE_PAISE << '\n';
    cout << "Middle fare (paise): " << MIDDLE_FARE_PAISE << '\n';
    cout << "Outer fare (paise): " << OUTER_FARE_PAISE << '\n';
    cout << "Peak surcharge (%): " << PEAK_SURCHARGE_PERCENT << '\n';
    cout << "Minimum balance (paise): " << MIN_BALANCE_PAISE << '\n';

    Zone currentZone = Zone::Middle;
    if (currentZone == Zone::Middle)
        cout << "Selected zone: Middle\n";
    return 0;
}
