#include <cstdio>
using namespace std;

int school[100010] = {0}; // 学校数量<=参赛人数

int main() {
    int n; scanf("%d", &n);
    int ans = -1, index, sch, grade; // 初始化最高分为-1 最高分学校 所属学校 选手得分
    while (n--) {
        scanf("%d %d", &sch, &grade); school[sch] += grade;
        if (school[sch] > ans) { // 更新最高分
            ans = school[sch]; index = sch;
        }
    }
    printf("%d %d\n", index, ans);
    return 0;
}
