#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

struct Fraction {
    ll up, down;
};

ll gcd(ll a, ll b) {
    a = abs(a); b = abs(b);
    return !b ? a : gcd(b, a%b);
}

Fraction simple(Fraction a) {
    if (a.down < 0) {
        a.down = -a.down; a.up = -a.up; // 虽然测试数据的分母不为0 但是运算过程中可能产生负分母
    }
    if (a.up == 0) a.down = 1;
    ll d = gcd(a.up, a.down);
    a.up /= d; a.down /= d;
    return a;
}

void print(Fraction a) {
    a = simple(a);
    bool neg = a.up < 0;
    if (neg) printf("(");
    if (a.down == 1) printf("%lld", a.up);
    else if (a.down == 0) printf("Inf");
    else if (abs(a.up) > a.down) printf("%lld %lld/%lld", a.up/a.down, abs(a.up)%a.down, a.down);
    else printf("%lld/%lld", a.up, a.down);
    if (neg) printf(")");
}

Fraction add(Fraction a, Fraction b) {
    a.up = a.up*b.down + b.up*a.down;
    a.down *= b.down;
    return a;
}

Fraction mul(Fraction a, Fraction b) {
    a.up *= b.up; a.down *= b.down;
    return a;
}

int main() {
    Fraction a, b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    print(a); printf(" + "); print(b); printf(" = "); print(add(a, b)); printf("\n");
    print(a); printf(" - "); print(b); printf(" = "); print(add(a, Fraction{-b.up, b.down})); printf("\n");
    print(a); printf(" * "); print(b); printf(" = "); print(mul(a, b)); printf("\n");
    print(a); printf(" / "); print(b); printf(" = "); print(mul(a, Fraction{b.down, b.up})); printf("\n");
    return 0;
}
