#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

int main() {
    int n, k; scanf("%d %d", &n, &k); // n个木棒 至少得到k段木棒 木棒不用整除
    int arr[maxn]; for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    sort(arr, arr+n);
    int left = 1, right = arr[n-1]; // 长度至少为1 至多为最长木棒的长度
    while (left < right) { // 找到第一个满足tmpK < k的长度L 然后L-1即为所求
        int mid = (left + right) / 2, tmpK = 0;
        for (int i = 0 ; i < n; ++i) tmpK += arr[i] / mid;
        if (tmpK >= k) left = mid+1;
        else right = mid;
    }
    printf("%d\n", left - 1);
    return 0;
}
