// 二分查找法 使用upper_bound函数
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn]; // a为升序

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a+n);
    int ans = 1; // 最大长度 至少有一个数
    for (int i = 0; i < n; ++i) {
        int end = upper_bound(a+i+1, a+n, (long long)a[i] * p) - a; // 上限为这个东西
        ans = max(ans, end - i);
    }
    printf("%d\n", ans);
    return 0;
}
