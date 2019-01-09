#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct mooncake {
    double amount, total, price;
};
bool cmp(mooncake a, mooncake b) {
    return a.price > b.price;
}
int main() {
    int n, d; cin >> n >> d;
    mooncake cakes[n];
    for (int i = 0; i < n; i++) cin >> cakes[i].amount;
    for (int i = 0; i < n; i++) {
        cin >> cakes[i].total;
        cakes[i].price = cakes[i].total / cakes[i].amount;
    }
    sort(cakes, cakes+n, cmp);
    double wage = 0.0;
    for (int i = 0; i < n && d; i++) {
        if (d >= cakes[i].amount) {
            wage += cakes[i].total;
            d -= cakes[i].amount;
        }
        else {
            wage += cakes[i].price * d;
            d = 0;
        }
    }
    cout << fixed << setprecision(2) << wage << endl;
    return 0;
}
