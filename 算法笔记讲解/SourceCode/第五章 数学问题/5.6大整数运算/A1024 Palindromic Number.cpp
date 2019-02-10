#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000;

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

void add(bign& a) {
    bign b = a;
    int carry = 0;
    for (int i = 0; i < a.len; ++i) {
        int tmp = a.d[i] + b.d[b.len-1-i] + carry;
        a.d[i] = tmp % 10;
        carry = tmp / 10;
    }
    if (carry) a.d[a.len++] = carry;
}

bool isP(bign a) {
    for (int i = 0, mid = a.len / 2; i <= mid; ++i) {
        if (a.d[i] != a.d[a.len-1-i]) return false;
    }
    return true;
}

int main() {
    char str[maxn]; scanf("%s", str);
    bign a; change(str, a);
    int step; scanf("%d", &step);
    int cnt = 0;
    while (!isP(a) && cnt < step) {
        add(a); ++cnt;
    }
    for (int i = a.len-1; i >= 0; --i) printf("%d", a.d[i]);
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
