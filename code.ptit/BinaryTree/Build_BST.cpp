/*
Cho một mảng là phép duyệt level-order của cây nhị phân tìm kiếm.
Nhiệm vụ của bạn là xây dựng lại cây nhị phân tìm kiếm bảo toàn
được cấu trúc cây nhị phân ban đầu.
*/

#include <bits/stdc++.h>
using namespace std;

class node {
  public:
    int val;
    node *L, *R;
    node(int p) {
        val = p;
        L = R = NULL;
    }
};

void preOrder(node *root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->L);
    preOrder(root->R);
}

void addNode(node *root, int u) {
    if (u < root->val) {
        if (root->L == NULL) root->L = new node(u);
        else
            addNode(root->L, u);
    }
    if (u > root->val) {
        if (root->R == NULL) root->R = new node(u);
        else
            addNode(root->R, u);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> lev(n);
        cin >> lev[0];
        node *root = new node(lev[0]);
        for (int i = 1; i < n; i++) {
            cin >> lev[i];
            addNode(root, lev[i]);
        }
        preOrder(root);
        cout << "\n";
    }
    return 0;
}