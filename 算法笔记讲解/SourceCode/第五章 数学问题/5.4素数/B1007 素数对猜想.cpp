#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 10010; int n;
int prime[maxn] = {0}; // 先用非法值填充

bool isPrime(int a) {
    if (a <= 1) return false;
    int sqr = int(sqrt(1.0 * a));
    for (int i = 2; i <= sqr; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

void findPrime() {
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)) prime[cnt++] = i;
    }
}

int main() {
    scanf("%d", &n);
    findPrime();
    int ans = 0;
    for (int i = 1; prime[i]; ++i) { // 可能一个素数也没有
        if (prime[i] - prime[i-1] == 2) ++ans;
    }
    printf("%d\n", ans);
}

