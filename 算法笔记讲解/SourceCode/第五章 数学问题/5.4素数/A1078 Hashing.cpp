#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10010;
bool hashtable[maxn] = {0};

bool isPrime(int a) {
    if (a <= 1) return false;
    int sqr = int(sqrt(1.0 * a));
    for (int i = 2; i <= sqr; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int m, n, tmp, pos; scanf("%d %d", &m, &n);
    while (!isPrime(m)) ++m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        int step = 0; bool find = false;
        do {
            pos = (tmp + step * step) % m;
            if (pos >= m) break;
            if (!hashtable[pos]) {
                printf("%d", pos); hashtable[pos] = true;
                find = true; break;
            }
            ++step;
        } while (step < m);
        if (!find) printf("-");
        if (i != n-1) printf(" ");
        else printf("\n");
    }
    return 0;
}

