/*

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class node {
  public:
    int data;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;
    }

    void addNode(char x, int v) {
        node *p = new node(v);
        if (x == 'L') this->left = p;
        else if (x == 'R')
            this->right = p;
    }
};

node *Search(node *t, int u, char x) {
    // check if left or right is NULL
    if (t->data == u)
        if ((x == 'L' && t->left == NULL) || (x == 'R' && t->right == NULL)) return t;
    if (t == NULL) return NULL;
    node *p = Search(t->left, u, x);
    if (p == NULL) p = Search(t->right, u, x);
    return p;
}

bool isLeaf(node *p) {
    if (p == NULL) return false;
    // return (p->left == NULL && p->right == NULL);
    if (p->left == NULL && p->right == NULL) return true;
    return false;
}

int sumLeftLeaves(node *p) {
    if (p == NULL) return 0;
    int res = 0;
    if (p->left != NULL) {
        if (isLeaf(p->left)) res += p->left->data;
        else
            res += sumLeftLeaves(p->left);
    }
    if (p->right != NULL && !isLeaf(p->right)) res += sumLeftLeaves(p->right);
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;
        cin >> n >> u >> v >> x;
        node *root = new node(u);
        root->addNode(x, v);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            node *p = Search(root, u, x);
            p->addNode(x, v);
        }
        // preOrder(root);
        cout << sumLeftLeaves(root) << "\n";
    }
    return 0;
}