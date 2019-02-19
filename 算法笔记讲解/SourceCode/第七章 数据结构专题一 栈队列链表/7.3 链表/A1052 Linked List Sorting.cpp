#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

struct node {
    int address, data, next;
    bool flag; // 标记是否为有效节点
}nodes[maxn];

bool cmp(node a, node b) {
    return a.flag != b.flag ? a.flag > b.flag : a.data < b.data;
}

int main() {
    for (int i = 0; i < maxn; ++i) nodes[i].flag = false;
    int n, head; scanf("%d %d", &n, &head);
    for (int i = 0; i < n; ++i) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        nodes[a] = {a, b, c};
    }
    int cnt = 0;
    for (int p = head; p != -1; p = nodes[p].next) {
        nodes[p].flag = true;
        ++cnt;
    }
    if (!cnt) { // 最后一个测试点 在给定头节点的情况下居然会没有有效节点= =？
        printf("0 -1\n"); return 0;
    }
    sort(nodes, nodes+maxn, cmp);
    printf("%d %05d\n", cnt, nodes[0].address);
    for (int i = 0; i < cnt; ++i) {
        printf("%05d %d ", nodes[i].address, nodes[i].data);
        if (i != cnt-1) printf("%05d\n", nodes[i+1].address);
        else printf("-1\n");
    }
    return 0;
}
