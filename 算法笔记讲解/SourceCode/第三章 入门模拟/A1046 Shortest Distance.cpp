#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int sumDis[maxn] = {0}; // 从点i到点i+1的顺时针累计距离

int main() {
    int n, tmp, circle = 0; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp); sumDis[i] = sumDis[i-1] + tmp; circle += tmp;
    }
    int m, s, e; scanf("%d", &m);
    while (m--) {
        scanf("%d %d", &s, &e); if (s > e) swap(s, e);
        int tmp = sumDis[e-1] - sumDis[s-1]; // 去i而不是i+1 所以索引-1
        printf("%d\n", min(tmp, circle-tmp));
    }
    return 0;
}
