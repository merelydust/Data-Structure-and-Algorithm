#include <cstdio>
#include <map>
#include <vector>
#include <functional>
using namespace std;

int n, m, id, k, child;
vector<int> v[110];
int mp[110] = {0};

void dfs(int now, int layer) {
    ++mp[layer];
    if (v[now].empty()) return;
    for (int i = 0; i < v[now].size(); ++i) dfs(v[now][i], layer+1);
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &id, &k);
        while (k--) {
            scanf("%d", &child); v[id].push_back(child);
        }
    }
    dfs(1, 1);
    int maxLayer = 0, maxValue = -1;
    for (int i = 1; i < 110; ++i) {
        if (mp[i] > maxValue) {
            maxValue = mp[i]; maxLayer = i;
        }
    }
    printf("%d %d\n", maxValue, maxLayer);
    return 0;
}
