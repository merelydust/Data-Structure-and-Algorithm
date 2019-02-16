// 用哈希表会内存超限= =
#include <cstdio>
#include <set>
using namespace std;
const int N = 51;

int main() {
    int n, m, q, v, st1, st2;
    set<int> st[N];
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &m);
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v); st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &st1, &st2);
        int totalNum = (int)st[st2].size(), sameNum = 0;
        for (auto it = st[st1].begin(); it != st[st1].end(); ++it) {
            if (st[st2].find(*it) != st[st2].end()) sameNum++;
            else totalNum++;
        }
        printf("%.1lf%%\n", sameNum * 100.0 / totalNum); // 先乘再除 比 先除再乘 误差小
    }
    return 0;
}
