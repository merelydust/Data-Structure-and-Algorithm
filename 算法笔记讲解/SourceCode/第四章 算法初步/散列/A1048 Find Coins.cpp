#include <cstdio>
using namespace std;
const int maxn = 1010;
int hashtable[1010] = {0}; // 下标对应面额

int main() {
    int n, m, tmp; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp); ++hashtable[tmp];
    }
    for (int i = 1; i < maxn; ++i) { // 不能<=500 题目的bug
        if (hashtable[i] && hashtable[m-i]) {
            if (i == m-i && hashtable[i] < 2) continue;
            printf("%d %d\n", i, m-i); return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}
