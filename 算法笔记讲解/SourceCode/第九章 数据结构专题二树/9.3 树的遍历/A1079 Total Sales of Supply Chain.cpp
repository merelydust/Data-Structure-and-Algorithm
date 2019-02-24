#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 100010;
double rootPrice, r, ans;

struct node {
    int products;
    vector<int> children;
}nodes[maxn];

void dfs(int now, int layer) {
    if (nodes[now].children.empty()) {
        ans += nodes[now].products * rootPrice * pow(1+r, layer); // 根的layer是0 即没有加价
        return;
    }
    for (int i = 0; i < nodes[now].children.size(); ++i) {
        dfs(nodes[now].children[i], layer+1);
    }
}

int main() {
    int n;
    ans = 0;
    scanf("%d %lf %lf", &n, &rootPrice, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        int k, child; scanf("%d", &k);
        if (k == 0) scanf("%d", &nodes[i].products);
        while (k--) {
            scanf("%d", &child);
            nodes[i].children.push_back(child);
        }
    }
    dfs(0, 0);
    printf("%.1f\n", ans);
    return 0;
}
