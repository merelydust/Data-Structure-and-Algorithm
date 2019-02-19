#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int hashtable[maxn] = {0};
struct node {
    int address, data, next;
}nodes[maxn];

int main() {
    int head, n; scanf("%d %d", &head, &n);
    node tmp;
    while (n--) {
        scanf("%d %d %d", &tmp.address, &tmp.data, &tmp.next);
        nodes[tmp.address] = tmp;
    }
    node headNode = nodes[head]; bool end = false;
    vector<node> uv, v;
    while (!end) {
        if (hashtable[abs(headNode.data)]) v.push_back(headNode);
        else {
            uv.push_back(headNode); hashtable[abs(headNode.data)] = 1;
        }
        if (headNode.next == -1) break;
        headNode = nodes[headNode.next];
    }
    for (int i = 0, len = uv.size(); i < len; ++i) {
        printf("%05d %d ", uv[i].address, uv[i].data);
        if (i == len-1) printf("-1\n");
        else printf("%05d\n", uv[i+1].address);
    }
    for (int i = 0, len = v.size(); i < len; ++i) {
        printf("%05d %d ", v[i].address, v[i].data);
        if (i == len-1) printf("-1\n");
        else printf("%05d\n", v[i+1].address);
    }
}

