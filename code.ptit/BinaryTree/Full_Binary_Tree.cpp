/*
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây
nhị phân có phải là một cây đủ hay không (full binary tree)?
Một cây nhị phân được gọi là cây đủ nếu tất cả các
node trung gian của nó đều có hai node con.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, degree;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->degree = 0;
        this->left = this->right = NULL;
    }

    void addNode(char x, node *p) {
        if (x == 'L' && this->left == NULL) {
            this->left = p;
            this->degree++;
        } else if (x == 'R' && this->right == NULL) {
            this->right = p;
            this->degree++;
        }
    }
};

node *Search(node *t, int u) {
    if (t == NULL || t->data == u) return t;
    else {
        node *p = Search(t->left, u);
        if (p == NULL) p = Search(t->right, u);
        return p;
    }
};

bool BFS(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *v = q.front();
        q.pop();
        if ((v->left != NULL || v->right != NULL) && v->degree == 1) return false;
        if (v->left != NULL) q.push(v->left);
        if (v->right != NULL) q.push(v->right);
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;
        cin >> n >> u >> v >> x;
        node *root = new node(u);
        node *p1, *p2;
        p1 = new node(v);
        root->addNode(x, p1);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            p1 = Search(root, u);
            p2 = new node(v);
            p1->addNode(x, p2);
        }
        if (BFS(root)) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}