#include <iostream>
#include <map>
using namespace std;

int main() {
    int k1, k2;
    map<int,double, greater<int>> m;
    cin >> k1;
    while (k1--) {
        int ex; double co;
        cin >> ex >> co; m[ex] += co;
    }
    cin >> k2;
    while (k2--) {
        int ex; double co;
        cin >> ex >> co; m[ex] += co;
    }
    map<int, double>::iterator it;
    int cnt = 0;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second) cnt++; // 系数为0不输出
    }
    cout << cnt;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second) printf(" %d %.1f", it->first, it->second);
    }
    return 0;
}

