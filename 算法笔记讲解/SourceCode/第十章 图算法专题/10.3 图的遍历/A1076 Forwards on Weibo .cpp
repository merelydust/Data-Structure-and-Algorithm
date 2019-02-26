#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1010;

struct node {
    int id, layer;
};
vector<node> Adj[maxn];
bool inq[maxn] = {0};
int n, l, k, num, id;

int bfs(node now) {
    queue<node> Q;
    Q.push(now); inq[now.id] = true;
    int cnt = 0;
    while (!Q.empty()) {
        node fro = Q.front();
        Q.pop();
        for (int i = 0; i < Adj[fro.id].size(); ++i) { // fro写成now找了半天(吐血
            node v = Adj[fro.id][i];
            v.layer = fro.layer + 1;
            if (!inq[v.id]) {
                if (v.layer > l) return cnt;
                Q.push(v); inq[v.id] = true;
                ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num);
        while (num--) {
            scanf("%d", &id);
            Adj[id].push_back(node{i, 0}); // 邻接表存储粉丝
        }
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        memset(inq, false, sizeof(inq));
        printf("%d\n", bfs(node{id, 0}));
    }
    return 0;
}
