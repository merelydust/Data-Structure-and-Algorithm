#include <cstdio>
using namespace std;

int main() {
    int t; scanf("%d", &t);
    long long a, b, c;
    for (int i = 1; i <= t; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: ", i);
        if (a + b > c) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
