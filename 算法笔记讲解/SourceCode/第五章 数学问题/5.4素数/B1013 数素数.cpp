#include <cstdio>
#include <cmath>
using namespace std;

bool isPrime(int a) {
    if (a <= 1) return false;
    int sqr = int(sqrt(1.0 * a));
    for (int i = 2; i <= sqr; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

int main() {
    int m, n; scanf("%d %d", &m, &n);
    int prime[10010], cnt = 0, i = 2;
    while (cnt < n) {
        if (isPrime(i)) prime[cnt++] = i;
        ++i;
    }
    int j = m-1;
    while (j < n) {
        int line = 0;
        while (line < 10 && j < n) {
            printf("%d", prime[j]); ++line; ++j;
            if (line != 10 && j != n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
