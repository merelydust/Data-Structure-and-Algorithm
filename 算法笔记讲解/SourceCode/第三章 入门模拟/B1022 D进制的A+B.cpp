#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d; scanf("%d %d %d", &a, &b, &d);
    c = a + b;
    int arr[31] = {0}, len = 0; // 数组模拟数字
    do {
        arr[len++] = c % d; // 数组低位对应数字低位
        c /= d;
    } while (c);
    for (int i = len-1; i >= 0; --i) printf("%d", arr[i]); // 从高位到低位输出
    printf("\n");
    return 0;
}
