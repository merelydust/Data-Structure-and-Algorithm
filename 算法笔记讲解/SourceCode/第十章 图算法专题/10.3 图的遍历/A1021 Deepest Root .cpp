#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;
const int maxn = 10010;
vector<int> Adj[maxn];
// bool vis[maxn] = {false}; 不需要判断是否访问过了 因为你是在寻找最长路径 不是在遍历图啊喂！
int father[maxn];
set<int> ans; vector<int> tmp;
int n, u, v, maxDepth;

void init() {
    for (int i = 1; i <= n; ++i) father[i] = i;
}

int findFather(int x) {
    int a = x;
    while (father[x] != x) x = father[x];
    while (a != x) {
        int b = a;
        a = father[a];
        father[b] = x;
    }
    return x;
}

void unionFather(int x, int y) {
    int faX = findFather(x), faY = findFather(y);
    if (faX != faY) father[faX] = faY; // 注意 是father[faX] = faY 不是father[x] = faY
}

void dfs(int u, int pre, int depth) {
    if (depth > maxDepth) {
        maxDepth = depth;
        tmp.clear(); tmp.push_back(u);
    }
    else if (depth == maxDepth) tmp.push_back(u);
    for (int i = 0; i < Adj[u].size(); ++i) {
        int v = Adj[u][i];
        if (v == pre) continue; // 无向图不走回头路
        dfs(v, u, depth+1);
    }
}

int main() {
    scanf("%d", &n);
    init();
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &u, &v);
        Adj[u].push_back(v); Adj[v].push_back(u);
        unionFather(u, v);
    }
    unordered_set<int> numF;
    for (int i = 1; i <= n; ++i) numF.insert(findFather(i));
    if (numF.size() > 1) {
        printf("Error: %d components\n", int(numF.size()));
    }
    else {
        maxDepth = 0;
        dfs(1, -1, 1);
        for (auto it = tmp.begin(); it != tmp.end(); ++it) ans.insert(*it);
        tmp.clear();
        maxDepth = 0; // 因为第一次求的的值不一定就是最大值
        dfs(*(ans.rbegin()), -1, 1);
        for (auto it = tmp.begin(); it != tmp.end(); ++it) ans.insert(*it);
        for (auto it = ans.begin(); it != ans.end(); ++it) printf("%d\n", *it);
    }
    return 0;
}
