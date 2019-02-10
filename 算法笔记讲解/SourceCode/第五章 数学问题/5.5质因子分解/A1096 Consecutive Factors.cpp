// 一个坑 两种情况下maxlen=1 n除了1和本身外只有一个因数 n为质数(maxlen不是0
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll n; scanf("%lld", &n);
    ll sqr = ll(sqrt(1.0 * n));
    ll maxlen = 0, start = n; // 如果最大长度为0就输出数字本身
    for (ll i = 2; i <= sqr; ++i) {
        ll j = i, tmp = i;
        while (n % tmp == 0) {
            ++j; tmp *= j;
        }
        if (j-i > maxlen) { // j-1-i+1 > maxlen
            maxlen = j-i; start = i;
        }
    }
    if (maxlen == 0) printf("1\n%lld", start);
    else {
        printf("%lld\n", maxlen);
        for (int i = 0; i < maxlen; ++i) {
            if (i != maxlen-1) printf("%lld*", start+i);
            else printf("%lld\n", start+i);
        }
    }
    return 0;
}
