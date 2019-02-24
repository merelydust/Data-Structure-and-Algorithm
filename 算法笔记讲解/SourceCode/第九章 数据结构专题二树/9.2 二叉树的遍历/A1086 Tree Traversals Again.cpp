#include <cstdio>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

vector<int> pre, in, post, value;
void create(int root, int inL, int inR) { // root-根节点在前序序列中的下标
    if (inL > inR) return;
    int pos = inL;
    while (in[pos] != pre[root] && pos < inR) ++pos;
    int numLeft = pos - inL;
    create(root+1, inL, pos-1); // 推入左子树
    create(root+1+numLeft, pos+1, inR); // 推入右子树
    post.push_back(pre[root]); // 推入根节点
}

int main() {
    int n, data, key = 0;
    scanf("%d", &n);
    char str[10] = {0};
    stack<int> s;
    while (~scanf("%s", str)) {
        if (strlen(str) == 4) {
            scanf("%d", &data);
            value.push_back(data);
            s.push(key);
            pre.push_back(key++);
        }
        else {
            in.push_back(s.top());
            s.pop();
        }
    }
    create(0, 0, n-1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; ++i) printf(" %d", value[post[i]]);
    printf("\n");
    return 0;
}
