#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;

int n, k, child, low, cnt;
double rootPrice, r;
vector<int> v[maxn];

void dfs(int now, int layer) {
    if (v[now].empty()) {
        if (layer < low) {
            low = layer;
            cnt = 1;
        }
        else if (layer == low) ++cnt;
        return;
    }
    for (int i = 0; i < v[now].size(); ++i) {
        if (layer + 1 > low) return;
        dfs(v[now][i], layer+1);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &rootPrice, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &child);
            v[i].push_back(child);
        }
    }
    low = maxn; cnt = 0;
    dfs(0, 0);
    printf("%.4f %d\n", rootPrice * pow(1+r, low), cnt);
    return 0;
}
