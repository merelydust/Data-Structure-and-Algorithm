/***
 判断n是否为素数
 把数字n以d进制表示dn 逆转得到rdn
 把rdn转化为十进制
 判断rn是否为素数
 ***/
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

bool isPrime(int a) {
    if (a <= 1) return false;
    int sqr = int(sqrt(1.0 * a));
    for (int i = 2; i <= sqr; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}

string toD(int n, int d) {
    string rdn = "";
    while (n) {
        rdn += to_string(n % d);
        n /= d;
    }
    return rdn;
}

int to10(string rdn, int d) {
    int rn = 0, mul = 1, len = int(rdn.length());
    for (int i = len - 1; i >= 0; --i) {
        rn += (rdn[i] - '0') * mul;
        mul *= d;
    }
    return rn;
}

int main() {
    int n, d; scanf("%d", &n);
    while (n > 0) {
        scanf("%d", &d);
        if (isPrime(n) && isPrime(to10(toD(n, d), d) ) ) printf("Yes\n");
        else printf("No\n");
        scanf("%d", &n);
    }
}
