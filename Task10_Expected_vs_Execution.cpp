#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long journeyCounts[] = {20000, 500000, 3000000};
    long long farePaise = 3000;

    double doubleFareRupees = 30.0;
    cout << fixed << setprecision(10);

    for (long long journeys : journeyCounts) {
        long long totalPaise = 1LL * journeys * farePaise;
        double totalRupees = journeys * doubleFareRupees;
        cout << "Journeys: " << journeys << '\n';
        cout << "Integer-paise total: " << totalPaise
             << " paise = Rs " << totalPaise / 100 << '\n';
        cout << "Double total: Rs " << totalRupees << '\n';
        cout << "--------------------------------\n";
    }

    int journeyCount = 3000000;
    int fareAsInt = 3000;
    long long safeTotal = 1LL * journeyCount * fareAsInt;
    cout << "Safe long long total paise: " << safeTotal << '\n';
    return 0;
}
