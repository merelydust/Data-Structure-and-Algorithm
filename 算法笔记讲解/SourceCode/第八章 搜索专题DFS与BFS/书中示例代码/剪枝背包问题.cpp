// 背包问题
#include <cstdio>
const int maxn = 30;
int n, V, maxValue = 0; // 物品件数n 背包容量V 最大价值maxValue
int w[maxn], c[maxn];

void dfs(int index, int sumW, int sumC) {
    if (index == n) { // 递归边界 已经完成对n件物品的选择
        return;
    }
    dfs(index+1, sumW, sumC); // 不选的分支
    if (sumW + w[index] <= V) {
        maxValue = sumC + c[index];
    }
    dfs(index+1, sumW+w[index], sumC + c[index]); // 选的分支
}
