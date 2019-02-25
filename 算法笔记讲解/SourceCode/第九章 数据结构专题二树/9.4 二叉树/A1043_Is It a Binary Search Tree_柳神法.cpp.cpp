// 先假设是BST 把前序序列转化为后序序列
// (前序序列首元素为根 左子树数据<=根节点数据<=右子树数据)
// 如果不是BST 转化函数会提前return 结果序列长度<n
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;

void getPost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    // 如果是BST 前序序列一定是 左左左leftEnd rightEnd右右右
    if(i - j != 1) return ;
    getPost(root + 1, j);
    getPost(i, tail);
    post.push_back(pre[root]);
}

int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &pre[i]);
    getPost(0, n-1);
    if (post.size() != n) {
        isMirror = true;
        post.clear();
        getPost(0, n-1);
    }
    if (post.size() == n) {
        printf("YES\n%d", post[0]);
        for (int i = 1; i < n; ++i) printf(" %d", post[i]);
    }
    else printf("NO\n");
    return 0;
}
