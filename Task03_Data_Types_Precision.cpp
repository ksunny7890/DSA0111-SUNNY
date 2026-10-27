#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main() {
    cout << "sizeof(bool) = " << sizeof(bool) << " byte(s)\n";
    cout << "sizeof(char) = " << sizeof(char) << " byte(s)\n";
    cout << "sizeof(int) = " << sizeof(int) << " byte(s)\n";
    cout << "sizeof(long long) = " << sizeof(long long) << " byte(s)\n";
    cout << "sizeof(double) = " << sizeof(double) << " byte(s)\n";
    cout << "INT_MAX = " << INT_MAX << '\n';
    cout << "LLONG_MAX = " << LLONG_MAX << '\n';

    long long totalPaise = 1LL * 3000000 * 3000;
    cout << "Network total (paise) = " << totalPaise << '\n';
    cout << "Network total (rupees) = " << totalPaise / 100 << '\n';

    double doubleTotal = 0.0;
    for (int i = 0; i < 100000; ++i) doubleTotal += 0.1;
    cout << fixed << setprecision(12);
    cout << "Adding 0.1 as double 100000 times = " << doubleTotal << '\n';
    cout << "Expected mathematical result = 10000.000000000000\n";
    return 0;
}
