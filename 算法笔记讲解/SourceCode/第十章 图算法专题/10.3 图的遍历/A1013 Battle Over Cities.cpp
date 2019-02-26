#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1010;
vector<int> Adj[maxn];
bool vis[maxn] = {false};
int n, m, k, u, v, destroy;

void dfs(int u) {
    if (u == destroy) return;
    vis[u] = true;
    for (int i = 0; i < Adj[u].size(); ++i) {
        if (!vis[Adj[u][i]]) dfs(Adj[u][i]);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        Adj[u].push_back(v); Adj[v].push_back(u);
    }
    while (k--) {
        scanf("%d", &destroy);
        memset(vis, 0, sizeof(vis));
        int block = 0;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && i != destroy) {
                ++block;
                dfs(i);
            }
        }
        printf("%d\n", block-1); // 需要新建的边数=连通块个数-1
    }
    return 0;
}

