/*

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, dir;
    node *left;
    node *right;

    node(int u) {
        this->data = u;
        this->dir = 0;
        this->left = this->right = NULL;
    }
    void addNode(char x, node *tmp) {
        if (x == 'L' && this->left == NULL) {
            tmp->dir = 1;
            this->left = tmp;
        } else if (x == 'R' && this->right == NULL) {
            tmp->dir = 2;
            this->right = tmp;
        }
    }
    void levelOrder() {
        long long sum = 0;
        queue<node *> q;
        q.push(this);
        while (!q.empty()) {
            node *v = q.front();
            q.pop();
            if (v->left == NULL && v->right == NULL && v->dir == 1) {
                // cout << v->data << " ";
                sum += (long long)v->data;
            }
            if (v->left != NULL) q.push(v->left);
            if (v->right != NULL) q.push(v->right);
        }
        cout << sum << "\n";
    }
};

node *nodeSearch(node *t, int u) {
    if (t == NULL || (t->left == NULL && t->right == NULL && t->data == u)) return t;
    else {
        node *p = nodeSearch(t->left, u);
        if (p == NULL) p = nodeSearch(t->right, u);
        return p;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;
        cin >> n >> u >> v >> x;
        node *root = new node(u);
        node *tmp = new node(v);
        root->addNode(x, tmp);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            tmp = nodeSearch(root, u);
            node *tmp1 = new node(v);
            tmp->addNode(x, tmp1);
        }
        root->levelOrder();
    }
    return 0;
}