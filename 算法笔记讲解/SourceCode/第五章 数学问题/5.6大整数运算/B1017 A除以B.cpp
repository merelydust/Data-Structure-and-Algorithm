#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1010;

struct bign {
    int len, d[maxn];
    bign() {
        len = 0; memset(d, 0, sizeof(d));
    }
};

void change(char str[], bign& a) {
    a.len = int(strlen(str));
    for (int i = 0; i < a.len; ++i) a.d[i] = str[a.len-1-i] - '0';
}

int divide(bign a, int b, bign& ans) {
    int r = 0;
    for (int i = a.len-1; i >= 0; --i) {
        r = a.d[i] + r*10;
        if (r < b) ans.d[i] = 0;
        else {
            ans.d[i] = r / b;
            r = r % b;
        }
    }
    while (ans.d[ans.len-1] == 0 && ans.len > 1) --ans.len;
    return r;
}

int main() {
    bign a; char tmp[maxn]; int b;
    scanf("%s", tmp); change(tmp, a);
    scanf("%d", &b);
    bign ans = a;
    int r = divide(a, b, ans);
    for (int i = ans.len-1; i >= 0; --i) printf("%d", ans.d[i]);
    printf(" %d\n", r);
    return 0;
}
