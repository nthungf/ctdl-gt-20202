/*

*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int data, level;
    node *left;
    node *right;

    node(int u) {
        this->data = u;
        this->level = 0;
        this->left = this->right = NULL;
    }
    void addNode(char x, node *tmp) {
        tmp->level = this->level + 1;
        if (x == 'L' && this->left == NULL) this->left = tmp;
        else if (x == 'R' && this->right == NULL)
            this->right = tmp;
    }
    void spiralOrder() {
        vector<int> res[1010];
        for (int i = 0; i < 1010; i++) res[i].clear();
        queue<node *> q;
        q.push(this);
        while (!q.empty()) {
            node *v = q.front();
            q.pop();
            res[v->level].push_back(v->data);
            // cout << v->data << " ";
            if (v->left != NULL) q.push(v->left);
            if (v->right != NULL) q.push(v->right);
        }
        int i = 0;
        while (!res[i].empty()) {
            if (i % 2 == 1)
                for (int j = 0; j < res[i].size(); j++) cout << res[i][j] << " ";
            else
                for (int j = res[i].size() - 1; j >= 0; j--) cout << res[i][j] << " ";
            i++;
        }
        cout << "\n";
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
        root->spiralOrder();
    }
    return 0;
}