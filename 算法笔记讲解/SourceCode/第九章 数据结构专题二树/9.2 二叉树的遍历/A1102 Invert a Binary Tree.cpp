#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 20;
bool isLeaf[maxn] = {0}, inq[maxn] = {0};
struct node {
    int left, right;
    node() {
        left = right = -1;
    }
}nodes[maxn];

void invert(int root) {
    if (root == -1) return;
    invert(nodes[root].left);
    invert(nodes[root].right);
    swap(nodes[root].left, nodes[root].right);
}

void layerTra(int root) {
    if (root == -1) return;
    queue<int> Q;
    Q.push(root); inq[root] = true;
    while (!Q.empty()) {
        int fro = Q.front();
        if (fro != root) printf(" ");
        printf("%d", fro);
        Q.pop();
        if (nodes[fro].left != -1) Q.push(nodes[fro].left);
        if (nodes[fro].right != -1) Q.push(nodes[fro].right);
    }
    printf("\n");
}

int cnt = 0, n;
void inorderTra(int Root) {
    if (Root == -1) return;
    inorderTra(nodes[Root].left);
    printf("%d", Root); ++cnt;
    if (cnt < n) printf(" ");
    inorderTra(nodes[Root].right);
}

int main() {
    scanf("%d", &n);
    char l, r;
    for (int i = 0; i < n; ++i) {
        scanf(" %c %c", &l, &r); // 最前的空格吸收换行符
        if (l == '-') nodes[i].left = -1;
        else {
            nodes[i].left = l - '0';
            isLeaf[nodes[i].left] = true;
        }
        if (r == '-') nodes[i].right = -1;
        else {
            nodes[i].right = r - '0';
            isLeaf[nodes[i].right] = true;
        }
    }
    int root = -1;
    for (int i = 0; i < n; ++i) {
        if (!isLeaf[i]) {
            root = i; break;
        }
    }
    invert(root);
    layerTra(root);
    inorderTra(root); printf("\n");
    return 0;
}
