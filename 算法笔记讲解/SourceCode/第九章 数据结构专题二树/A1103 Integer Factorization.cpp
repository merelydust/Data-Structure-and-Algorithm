#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int n, sqr, k, p, maxSumFac = -1;
vector<int> tmp, ans, squares;

void init() { // 打表解决超时
    for (int i = 0; i <= sqr; ++i) {
        int num = 1;
        for (int j = 0; j < p; ++j) num *= i;
        squares.push_back(num);
    }
}

void dfs(int index, int nowK, int sumNum, int sumFac) {
    if (nowK == k && sumNum == n) {
        if (sumFac > maxSumFac) {
            maxSumFac= sumFac;
            ans = tmp;
        }
        return;
    }
    if (index == 0 || nowK > k || sumNum > n) return;
    
    tmp.push_back(index); // 选的分支
    dfs(index, nowK + 1, sumNum + squares[index], sumFac + index);
    tmp.pop_back(); // 不选的分支
    dfs(index-1, nowK, sumNum, sumFac);
}

int main() {
    scanf("%d %d %d", &n, &k, &p);
    sqr = int(sqrt(1.0 * n));
    init();
    dfs(sqr, 0, 0, 0);
    if (maxSumFac == -1) printf("Impossible\n");
    else {
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); ++i) {
            if (i) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
        printf("\n");
        return 0;
    }
}
   
