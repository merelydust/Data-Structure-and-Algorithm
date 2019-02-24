#include <cstdio>
#include <vector>
#include <map>
using namespace std;
const int maxn = 110;

int n, m, id, k, child;
vector<int> v[maxn];
map<int, int> mp;

void dfs(int now, int layer) {
    if (v[now].empty()) {
        ++mp[layer];
        return;
    }
    for (int i = 0; i < v[now].size(); ++i) {
        dfs(v[now][i], layer+1);
    }
}

int main() {
    scanf("%d", &n);
    if (!n) return 0;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &id, &k);
        while (k--) {
            scanf("%d", &child);
            v[id].push_back(child);
        }
    }
    dfs(1, 1);
    int maxLayer = mp.rbegin()->first;
    for (int i = 1; i <= maxLayer; ++i) {
        printf("%d", mp[i]);
        if (i != maxLayer) printf(" ");
        else printf("\n");
    }
    return 0;
}
