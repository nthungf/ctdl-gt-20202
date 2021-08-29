/*
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem cây nhị phân
có phải là một cây hoàn hảo hay không (perfect tree)?
Một cây nhị phân được gọi là cây hoàn hảo nếu tất cả các node trung gian
của nó đều có hai node con và tất cả các node lá đều có cùng một mức.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, level, degree;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->level = this->degree = 0;
        this->left = this->right = NULL;
    }

    void addNode(char x, node *p) {
        p->level = this->level + 1;
        if (x == 'L' && this->left == NULL) {
            this->degree++;
            this->left = p;
        } else if (x == 'R' && this->right == NULL) {
            this->degree++;
            this->right = p;
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
}

bool BFS(node *root) {
    vector<int> res;
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        node *v = q.front();
        q.pop();
        if (v->left == NULL && v->right == NULL) res.push_back(v->level);
        else {
            if (v->degree == 1) return false;
        }
        if (v->left != NULL) q.push(v->left);
        if (v->right != NULL) q.push(v->right);
    }
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] != res[i + 1]) return false;
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
        if (BFS(root)) cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}