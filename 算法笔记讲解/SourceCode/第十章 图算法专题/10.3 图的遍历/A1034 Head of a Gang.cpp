#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int id = 1; // 给人名编码
map<string, int> mp;
map<int, string> rmp;
map<string, int> gang;
const int maxn = 2020;
int n, k;
int G[maxn][maxn] = {0}, weight[maxn] = {0};
bool vis[maxn] = {false};

int getId(string s) {
    if (!mp[s]) {
        mp[s] = id;
        rmp[id] = s;
        return id++;
    }
    else return mp[s];
}

void dfs(int u, int& cnt, int& w, int& head) {
    vis[u] = true; ++cnt;
    if (weight[u] > weight[head]) head = u;
    for (int v = 1; v < maxn; ++v) {
        if (G[u][v] > 0) { // 判断vis放到了后面是避免环的影响
            w += G[u][v]; G[u][v] = G[v][u] = 0;
            if (!vis[v]) dfs(v, cnt, w, head);
        }
    }
}


int main() {
    cin >> n >> k;
    string a, b; int time;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> time;
        int id1 = getId(a), id2 = getId(b);
        G[id1][id2] += time; G[id2][id1] += time;
        weight[id1] += time; weight[id2] += time; // 多存储一份权重是为了判断head 因为在图遍历中会清除重复边权
    }
    for (int u = 1; u < maxn; ++u) {
        if (!vis[u]) {
            int cnt = 0, w = 0, head = u;
            dfs(u, cnt, w, head);
            if (cnt > 2 && w > k) {
                gang[rmp[head]] = cnt;
            }
        }
    }
    printf("%d\n",int(gang.size()));
    for (auto it = gang.begin(); it != gang.end(); ++it) printf("%s %d\n", (it->first).c_str(), it->second);
    return 0;
}

