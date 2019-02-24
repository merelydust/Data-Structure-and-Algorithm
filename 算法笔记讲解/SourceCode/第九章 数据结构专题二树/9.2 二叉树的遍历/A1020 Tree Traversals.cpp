#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 40;
int post[maxn], in[maxn];

struct node {
    int data;
    node* left;
    node* right;
    node() {
        left = right = NULL;
    }
};

node* create(int postL, int postR, int inL, int inR) {
    if (postL > postR) return NULL;
    node* root = new node;
    root->data = post[postR];
    int pos = inL;
    while (in[pos] != root->data) ++pos;
    int numLeft = pos - inL;
    root->left = create(postL, postL+numLeft-1, inL, pos-1);
    root->right = create(postL+numLeft, postR-1, pos+1, inR);
    return root;
}

void layerTra(node* root) {
    queue<node*> Q;
    Q.push(root);
    while (!Q.empty()) {
        node* fro = Q.front();
        if (fro->data != root->data) printf(" ");
        printf("%d", fro->data);
        Q.pop();
        if (fro->left != NULL) Q.push(fro->left);
        if (fro->right != NULL) Q.push(fro->right);
    }
    printf("\n");
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &post[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &in[i]);
    node* root = create(0, n-1, 0, n-1);
    layerTra(root);
    return 0;
}
