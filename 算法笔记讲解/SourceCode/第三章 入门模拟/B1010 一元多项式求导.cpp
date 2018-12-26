#include <iostream>
using namespace std;

int main() {
    int co, index;
    int cnt = 0;
    while (cin >> co >> index) {
        if (index) {
            if (cnt) cout << ' ';
            co = index * co;
            --index;
            cout << co << ' ' << index;
            cnt++;
        }
    }
    if (cnt == 0) cout << "0 0";
    return 0;
}
