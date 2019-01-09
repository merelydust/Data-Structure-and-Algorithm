#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn]; // 下标数字对应其所处位置

int main() {
    int n, num, unsort = 0, cnt = 0; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num); pos[num] = i;
        if (num && pos[num] != num) ++unsort; // 除了0以外的错乱数字个数
    }
    int start = 1; // 为防止超时 记录无序子序列的开始位置
    while (unsort) {
        if (pos[0] == 0) {
            while (start < n) {
                if (pos[start] != start) break;
                ++start;
            }
            swap(pos[0], pos[start]); ++cnt; // 交换0和找到的第一个不在本位的数字的位置
        }
        while (pos[0] != 0) {
            swap(pos[0], pos[pos[0]]); ++cnt; --unsort; // 把0所占的数字pos[0]的位置还给它 数字pos[0]的位置在pos[pos[0]]
        }
    }
    printf("%d\n", cnt);
}
