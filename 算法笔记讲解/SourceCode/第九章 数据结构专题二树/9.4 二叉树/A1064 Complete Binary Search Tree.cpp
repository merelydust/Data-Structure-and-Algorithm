// 有序序列=BST中序遍历序列
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, cnt = 0, arr[maxn], cbt[maxn];

void inOrder(int root) {
    if (root > n) return;
    inOrder(2*root);
    cbt[root] = arr[cnt++];
    inOrder(2*root+1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    inOrder(1);
    for (int i = 1; i <=n; ++i) {
        printf("%d", cbt[i]);
        if (i != n) printf(" ");
        else printf("\n");
    }
    return 0;
}
