#include <cstdio>
int father[110];

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
    if (father[x] != father[y]) father[faX] = faY;
}

int main() {
    int n, m, a, b; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) father[i] = i;
    while (m--) {
        scanf("%d %d", &a, &b);
        unionFather(a, b);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (father[i] == i) ++cnt;
    }
    printf("%d\n", cnt);
    return 0;
}
