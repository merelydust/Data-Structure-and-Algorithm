#include <cstdio>
#include <cstdlib> // 用cmath会报错ambiguous reference
using namespace std;
typedef long long ll;

struct Fraction {
    ll up, down;
};

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

void simple(Fraction& a) {
    if (a.down < 0) {
        a.down = -a.down; a.up = -a.up;
    }
    if (a.up == 0) a.down = 1;
    else {
        ll d = gcd(a.up, a.down);
        a.down /= d; a.up /= d;
    }
}

void print(Fraction a) {
    if (a.down == 1) printf("%lld\n", a.up);
    else if (abs(a.up) > a.down) printf("%lld %lld/%lld\n", abs(a.up)/a.down, abs(a.up)%a.down, a.down);
    else printf("%lld/%lld\n", a.up, a.down);
}

void add(Fraction& a, Fraction b) {
    a.up = a.up * b.down + b.up * a.down;
    a.down *= b.down;
    simple(a);
}

int main() {
    int n; scanf("%d", &n);
    Fraction ans = Fraction{0, 1}, tmp;
    while (n--) {
        scanf("%lld/%lld", &tmp.up, &tmp.down);
        add(ans, tmp);
    }
    print(ans);
    return 0;
}
