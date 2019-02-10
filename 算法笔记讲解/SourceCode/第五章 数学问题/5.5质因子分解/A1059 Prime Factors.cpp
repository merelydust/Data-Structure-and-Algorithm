// 一个坑 虽然题目说输出素数 但1=1也要输出
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

bool isPrime(ll n) {
    if (n <= 1) return false;
    ll sqr = ll(sqrt(1.0 * n));
    for (ll i = 2; i <= sqr; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ll n; scanf("%lld", &n);
    printf("%lld=", n);
    if (n == 1) {
        printf("1"); return 0;
    }
    ll sqr = ll(sqrt(1.0 * n));
    bool flag = false;
    for (ll i = 2; i <= sqr; ++i) {
        if (isPrime(i)) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i; ++cnt;
            }
            if (cnt) {
                if (flag) printf("*");
                printf("%lld", i);
                flag = true; // 标记已经有数字输出
            }
            if (cnt > 1) printf("^%d", cnt);
        }
    }
    if (n > 1) {
        if (flag) printf("*");
        printf("%lld", n);
    }
    return 0;
}
