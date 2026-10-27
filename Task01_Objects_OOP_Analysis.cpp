#include <iostream>
#include <string>
using namespace std;

class SmartCard {
private:
    string cardId;
    long long balancePaise;

public:
    SmartCard(string id, long long balance) : cardId(id), balancePaise(balance) {}

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 && balancePaise >= farePaise &&
               balancePaise - farePaise >= 5000;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise -= farePaise;
        return true;
    }

    long long getBalance() const { return balancePaise; }
    string getCardId() const { return cardId; }
};

int main() {
    SmartCard card("CARD101", 10000);
    long long farePaise = 2000;

    cout << "Card: " << card.getCardId() << '\n';
    if (card.deduct(farePaise))
        cout << "Journey accepted. Balance = Rs " << card.getBalance() / 100 << '\n';
    else
        cout << "Journey denied. Minimum balance must be Rs 50.\n";
    return 0;
}
