#include <cstdio>
const int maxn = 100010;
int nexts[maxn], hashtable[maxn] = {0};

int main() {
    int head1, head2, n; scanf("%d %d %d", &head1, &head2, &n);
    int address, next; char data;
    for (int i = 0; i < n; ++i) {
        scanf("%d %c %d", &address, &data, &next);
        nexts[address] = next;
    }
    int p;
    for (p = head1; p != -1; p = nexts[p]) hashtable[p] = 1;
    for (p = head2; p != -1; p = nexts[p]) {
        if (hashtable[p]) break;
    }
    if (p == -1) printf("-1\n");
    else printf("%05d\n", p);
}
