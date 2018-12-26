#include <cstdio>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    int cnt = 0;
    while (n != 1) {
        if (n % 2) { // 如果n是奇数
            n = (3*n + 1) / 2;
        }
        else n /= 2; // 如果n是偶数
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
