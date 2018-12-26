/***
 正方形一共四条边 上边下边正常循环打印即可
 左右两边 因为计算机是一行一行打印的 所以每一行只在行首行尾打印字符 中间是空格
 ***/

#include <cstdio>
using namespace std;

int main() {
    int n; char ch; scanf("%d %c", &n, &ch);
    for (int i = 0; i < n; ++i) printf("%c", ch); // 打印上边
    printf("\n");
    for (int i = 2, row = n / 2 + n % 2; i < row; ++i) { // 去除上下边 n如果是奇数 四舍五入行数要+1
        printf("%c", ch); // 行首
        for (int j = 0; j < n-2; ++j) printf(" "); // 中间n-2个空格
        printf("%c\n", ch); // 行尾 换行
    }
    for (int i = 0; i < n; ++i) printf("%c", ch); // 打印下边
    printf("\n");
    return 0;
}
