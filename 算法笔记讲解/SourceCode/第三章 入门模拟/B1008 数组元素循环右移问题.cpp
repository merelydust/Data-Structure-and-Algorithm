#include <cstdio>
using namespace std;
const int maxn = 110;

int main() {
    int n, m; scanf("%d %d", &n, &m); int arr[maxn] = {0};
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    m %= n; // 避免重复移动
    for (int i = n-m; i < n; ++i) printf("%d ", arr[i]);
    for (int i = 0; i < n-m; ++i) {
        printf("%d", arr[i]);
        if (i != n-m-1) printf(" ");
        else printf("\n");
    }
    return 0;
}
