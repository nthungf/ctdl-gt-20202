/*
Cho hai cây nhị phân, nhiệm vụ của bạn là kiểm tra xem
cây nhị phân có giống nhau hay không?
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data;
    node *left;
    node *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;
    }

    void addNode(char x, node *p) {
        if (x == 'L' && this->left == NULL) this->left = p;
        else if (x == 'R' && this->right == NULL)
            this->right = p;
    }
};

node *nodeSearch(node *t, int u) {
    if (t == NULL || t->data == u) return t;
    else {
        node *p = nodeSearch(t->left, u);
        if (p == NULL) p = nodeSearch(t->right, u);
        return p;
    }
}

bool compare(node *t1, node *t2) {
    if (t1 == NULL && t2 == NULL) return true;
    if (t1->data != t2->data) return false;
    return (compare(t1->left, t2->left) && compare(t1->right, t2->right));
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, u, v;
        char x;

        // cay 1
        cin >> n >> u >> v >> x;
        node *root1 = new node(u);
        node *tmp = new node(v);
        root1->addNode(x, tmp);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            tmp = nodeSearch(root1, u);
            node *p = new node(v);
            tmp->addNode(x, p);
        }

        // cay 2
        cin >> n >> u >> v >> x;
        node *root2 = new node(u);
        tmp = new node(v);
        root2->addNode(x, tmp);
        for (int i = 1; i < n; i++) {
            cin >> u >> v >> x;
            tmp = nodeSearch(root2, u);
            node *p = new node(v);
            tmp->addNode(x, p);
        }

        if (compare(root1, root2)) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}