/*

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;
    }

    void addNode(char x, node *pp) {
        if (x == 'L' && this->left == NULL) this->left = pp;
        else if (x == 'R' && this->right == NULL)
            this->right = pp;
    }
};

node *Search(node *t, int u) {
    if (t == NULL || t->data == u) return t;
    else {
        node *p = Search(t->left, u);
        if (p == NULL) p = Search(t->right, u);
        return p;
    }
}

bool isLeaf(node *p) {
    if (p == NULL) return false;
    return (p->left == NULL && p->right == NULL);
}

int sumRightLeaves(node *t) {
    int res = 0;
    if (t != NULL) {
        if (isLeaf(t->right)) res += t->right->data;
        else {
            res += sumRightLeaves(t->right);
        }
        res += sumRightLeaves(t->left);
    }
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
        node *p = new node(v);
        root->addNode(x, p);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            p = Search(root, u);
            node *p1 = new node(v);
            p->addNode(x, p1);
        }
        // preOrder(root);
        cout << sumRightLeaves(root) << "\n";
    }
    return 0;
}