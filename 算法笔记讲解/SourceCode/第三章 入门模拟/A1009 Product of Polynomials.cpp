#include <iostream>
#include <map>
using namespace std;

int main() {
    int k1, k2;
    map<int, double, greater<int> > m;
    double n1[10][2], n2[10][2]; // 乘法不像加法 指数会变 所以开两个二维数组方便计算
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        int ex; double co;
        cin >> ex >> co;
        n1[i][0] = ex;
        n1[i][1] = co;
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        int ex; double co;
        cin >> ex >> co;
        n2[i][0] = ex;
        n2[i][1] = co;
    }
    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            int ex = int(n1[i][0]) + int(n2[j][0]);
            double co = n1[i][1] * n2[j][1];
            m[ex] += co;
        }
    }
    map<int, double>::iterator it; int cnt = 0;
    for (it = m.begin(); it != m.end(); ++it) {
        if (it->second) cnt++;
    }
    cout << cnt;
    for (it = m.begin(); it != m.end(); it++) {
        if (!it->second) continue;
        printf(" %d %.1f", it->first, it->second);
    }
    printf("\n");
    return 0;
}
