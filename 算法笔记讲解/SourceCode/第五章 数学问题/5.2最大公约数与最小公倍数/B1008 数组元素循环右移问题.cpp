#include <cstdio>

int main() {
    int n, m; scanf("%d %d", &n, &m);
    m %= n;
    int arr[110];
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for (int i = n-m; i < n; ++i) printf("%d ", arr[i]); // 如果m=0 这个循环不会被执行
    for (int i = 0; i < n-m-1; ++i) printf("%d ", arr[i]);
    printf("%d\n", arr[n-m-1]);
    return 0;
}
