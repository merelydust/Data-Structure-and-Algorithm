#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 25;
int hashtable[maxn] = {0};

struct bign {
    int len, d[maxn];
    bign() {
        len = 0; memset(d, 0, sizeof(d));
    }
};

void change(char str[], bign& a) {
    a.len = int(strlen(str));
    for (int i = 0; i < a.len; ++i) {
        a.d[i] = str[a.len-1-i] - '0';
        ++hashtable[a.d[i]];
    }
}

bign mul(bign a) {
    bign b; int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        int tmp = a.d[i] * 2 + carry;
        carry = tmp / 10;
        b.d[b.len++] = tmp % 10;
    }
    if (carry) b.d[b.len++] = carry;
    return b;
}

int main() {
    char str[maxn]; scanf("%s", str);
    bign a; change(str, a);
    bign b = mul(a);
    bool flag = true;
    for (int i = 0; i < b.len; ++i) {
        if (!hashtable[b.d[i]]) {
            flag = false; break;
        }
        --hashtable[b.d[i]];
    }
    flag ? printf("Yes\n") : printf("No\n");
    for (int i = b.len-1; i >= 0; --i) {
        printf("%d", b.d[i]);
    }
    return 0;
}
