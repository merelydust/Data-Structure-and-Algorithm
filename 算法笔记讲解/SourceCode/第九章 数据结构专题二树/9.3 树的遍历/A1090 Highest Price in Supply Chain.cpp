#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int n, father, root, maxLayer, cnt;
double rootPrice, r;
vector<int> children[maxn];

void dfs(int now, int layer) {
    if (children[now].empty()) {
        if (layer > maxLayer) {
            maxLayer = layer;
            cnt = 1;
        }
        else if (layer == maxLayer) ++cnt;
        return;
    }
    for (int i = 0; i < children[now].size(); ++i) {
        dfs(children[now][i], layer+1);
    }
}

int main() {
    scanf("%d %lf %lf", &n, &rootPrice, &r);
    r /= 100;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &father);
        if (father != -1) children[father].push_back(i);
        else root = i;
    }
    maxLayer = 0; cnt = 0;
    dfs(root, 0);
    printf("%.2f %d\n", rootPrice * pow(1+r, maxLayer), cnt);
    return 0;
}
