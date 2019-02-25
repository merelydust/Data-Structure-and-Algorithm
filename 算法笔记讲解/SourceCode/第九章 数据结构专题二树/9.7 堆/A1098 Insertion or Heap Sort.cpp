#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void downAdjust(vector<int>& b, int low, int high) {
    int i = low, j = 2 * i;
    while (j <= high) {
        if (j+1 <= high && b[j+1] > b[j]) ++j;
        if (b[j] > b[i]) {
            swap(b[j], b[i]);
            i = j; j = 2 * i;
        }
        else break;
    }
}

int main() {
    int n, p = 2;
    scanf("%d", &n);
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    while (p <= n && b[p-1] <= b[p]) ++p; // 插入排序前几个数字会是升序
    int index = p; // 记录最后一个有序数字索引
    while (p <= n && a[p] == b[p]) ++p; // 前面几个数字是升序 剩下的数字又跟原始序列一样 -> 插入排序
    if (p == n+1) {
        printf("Insertion Sort\n");
        sort(b.begin(), b.begin() + index + 1); // 多排序一位
    }
    else {
        printf("Heap Sort\n");
        p = n;
        while (p > 2 && b[p] >= b[1]) --p; // 从后往前找到第一个小于当前堆顶的位置 就是无序序列的末尾
        swap(b[1], b[p]);
        downAdjust(b, 1, p-1);
    }
    printf("%d", b[1]);
    for (int i = 2; i <= n; ++i) printf(" %d", b[i]);
    return 0;
}
