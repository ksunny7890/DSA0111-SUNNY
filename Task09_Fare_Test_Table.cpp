#include <iostream>
#include <string>
using namespace std;

enum class Zone { Inner, Middle, Outer };

long long calculateFare(Zone zone, int hour) {
    long long base;
    switch (zone) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);
    if (peak) base += base * 20 / 100;
    return base;
}

int main() {
    struct TestCase {
        string name;
        Zone zone;
        int hour;
        long long expectedPaise;
    };

    TestCase tests[] = {
        {"Inner off-peak", Zone::Inner, 12, 1000},
        {"Middle 8 AM peak", Zone::Middle, 8, 2400},
        {"Outer 5 PM peak", Zone::Outer, 17, 3600},
        {"Outer 10 AM off-peak", Zone::Outer, 10, 3000},
        {"Middle 8 PM off-peak", Zone::Middle, 20, 2000}
    };

    int passed = 0;
    for (const auto& test : tests) {
        long long actual = calculateFare(test.zone, test.hour);
        bool ok = actual == test.expectedPaise;
        cout << test.name << ": expected " << test.expectedPaise
             << ", actual " << actual << " paise -> "
             << (ok ? "PASS" : "FAIL") << '\n';
        if (ok) ++passed;
    }
    cout << "Passed " << passed << " of " << (sizeof(tests) / sizeof(tests[0]))
         << " tests\n";
    return 0;
}
