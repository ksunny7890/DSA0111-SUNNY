#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };
constexpr long long FARES[] = {1000, 2000, 3000};
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

long long calculateFare(Zone zone, int hour) {
    long long amount = FARES[static_cast<int>(zone)];
    if (isPeakHour(hour)) amount += amount * 20 / 100;
    return amount;
}

class SmartCard {
private:
    long long balancePaise;
public:
    explicit SmartCard(long long initial) : balancePaise(initial) {}
    bool pay(long long farePaise) {
        if (farePaise < 0 || balancePaise < farePaise ||
            balancePaise - farePaise < MIN_BALANCE_PAISE) return false;
        balancePaise -= farePaise;
        return true;
    }
    long long balance() const { return balancePaise; }
};

int main() {
    SmartCard card(10000);
    long long fare = calculateFare(Zone::Middle, 8);
    cout << "Calculated fare (paise): " << fare << '\n';
    cout << (card.pay(fare) ? "Journey accepted\n" : "Journey denied\n");
    cout << "Remaining balance (paise): " << card.balance() << '\n';
    return 0;
}
