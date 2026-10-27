#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int hour;
    cout << "Enter hour (0-23): ";

    while (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour. Enter an integer from 0 to 23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long farePaise = 1050;
    cout << "Hour accepted: " << hour << '\n';
    cout << "Fare: Rs " << farePaise / 100 << '.'
         << setw(2) << setfill('0') << farePaise % 100 << '\n';
    return 0;
}
