#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, s;
vector<int> seq;

struct node {
    int w;
    vector<int> children;
}nodes[110];

bool cmp(int a, int b) {
    return nodes[a].w > nodes[b].w;
}

void dfs(int now, int sum) {
    if (nodes[now].children.empty() && sum == s) {
        for (int i = 0; i < seq.size(); ++i) {
            printf("%d", nodes[seq[i]].w);
            if (i != seq.size()-1) printf(" ");
            else printf("\n");
        }
        return;
    }
    if (sum > s || nodes[now].children.empty()) return;
    for (int i = 0; i < nodes[now].children.size(); ++i) {
        seq.push_back(nodes[now].children[i]);
        dfs(seq.back(), sum + nodes[seq.back()].w);
        seq.pop_back();
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; ++i) scanf("%d", &nodes[i].w);
    for (int i = 0; i < m; ++i) {
        int index, k, child;
        scanf("%d %d", &index, &k);
        while (k--) {
            scanf("%d", &child);
            nodes[index].children.push_back(child);
        }
        sort(nodes[index].children.begin(), nodes[index].children.end(), cmp);
    }
    seq.push_back(0);
    dfs(0, nodes[0].w);
    return 0;
}
