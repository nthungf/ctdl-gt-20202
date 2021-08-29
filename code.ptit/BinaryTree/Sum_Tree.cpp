/*
Cho cây nhị phân, nhiệm vụ của bạn là kiểm tra xem
cây nhị phân có phải là một cây tổng hay không?
Một cây nhị phân được gọi là cây tổng nếu tổng các
node con của node trung gian bằng giá trị node cha.
Node không có node con trái hoặc phải được hiểu
là có giá trị 0.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, sum;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->sum = -1;
        this->left = this->right = NULL;
    }

    void addNode(char x, node *p) {
        if (x == 'L' && this->left == NULL) this->left = p;
        else if (x == 'R' && this->right == NULL)
            this->right = p;
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

int ok;
void postOrder(node *t) {
    if (t == NULL) return;
    if (t->left == NULL && t->right == NULL) {
        t->sum = t->data;
        return;
    }
    postOrder(t->left);
    postOrder(t->right);
    int l = 0, r = 0;
    if (t->left != NULL) l = t->left->sum;
    if (t->right != NULL) r = t->right->sum;
    t->sum = l + r;
    // cout << t->data << " " << t->sum << "\n";
    if (t->data == t->sum) t->sum *= 2;
    else
        ok = 0;
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
        ok = 1;
        postOrder(root);
        if (ok) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}