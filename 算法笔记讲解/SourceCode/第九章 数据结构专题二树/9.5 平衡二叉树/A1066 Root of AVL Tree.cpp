#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int data, height;
    node* left;
    node* right;
    node() {
        left = right = NULL;
        height = 1;
    }
};

node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    return Node;
};

int getHeight(node* root) {
    if (root == NULL) return 0;
    return root->height;
}

void updateHeight(node* root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

int getBF(node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

void L(node* &root) {
    node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node* &root) {
    node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(node* &root, int v) {
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    else if (v < root->data) {
        insert(root->left, v);
        updateHeight(root);
        if (getBF(root) == 2) { // 左子树失衡
            if (getBF(root->left) == 1) R(root); // 左左型
            else if (getBF(root->left) == -1) { // 左右型
                L(root->left);
                R(root);
            }
        }
    }
    else if (v > root->data) {
        insert(root->right, v);
        updateHeight(root);
        if (getBF(root) == -2) { // 右子树失衡
            if (getBF(root->right) == -1) L(root); // 右右型
            else if (getBF(root->right) == 1) { // 右左型
                R(root->right);
                L(root);
            }
        }
    }
}

int main() {
    int n, v; scanf("%d", &n);
    node* root = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        insert(root, v);
    }
    printf("%d\n", root->data);
}

