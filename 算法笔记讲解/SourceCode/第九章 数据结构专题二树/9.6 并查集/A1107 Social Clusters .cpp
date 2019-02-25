#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1010;
map<int, vector<int> > hobby;
map<int, int> cnt;
int father[maxn];

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
    if (faX != faY) father[faX] = faY;
}

int main() {
    int n, k, h; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) father[i] = i; // 记得初始化
    for (int i = 1; i <= n; ++i) {
        scanf("%d: ", &k);
        while (k--) {
            scanf("%d", &h);
            if (hobby[h].empty()) hobby[h].push_back(i);
            else unionFather(i, hobby[h].back());
        }
    }
    for (int i = 1; i <= n; ++i) ++cnt[findFather(i)]; // ++cnt[father[i]]是错的
    printf("%d\n", (int)cnt.size());
    vector<int> ans;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) ans.push_back(it->second);
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i != ans.size()-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
