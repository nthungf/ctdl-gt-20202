/*
Cho mảng A[] gồm N node là biểu diễn phép duyệt theo
thứ tự giữa (Preorder) của cây nhị phân tìm kiếm.
Nhiệm vụ của bạn là đưa ra phép duyệt theo thứ tự sau
của cây nhị phân tìm kiếm.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

class node {
  public:
    int data;
    node *left, *right;

    node(int p) {
        this->data = p;
        this->left = this->right = NULL;
    }
};

void postOrder(node *p) {
    if (p != NULL) {
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

void buildBST(node *p, int l, int r) {
    if (l > r || l >= n || r >= n) return;
    int rl = l + 1;
    while (a[rl] < a[l]) rl++;
    if (rl < n) {
        if (l + 1 <= rl - 1) {
            p->left = new node(a[l + 1]);
            buildBST(p->left, l + 1, rl - 1);
        }
        if (rl <= r) {
            p->right = new node(a[rl]);
            buildBST(p->right, rl, r);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        node *root = new node(a[0]);
        buildBST(root, 0, n - 1);
        postOrder(root);
        cout << "\n";
    }
    return 0;
}