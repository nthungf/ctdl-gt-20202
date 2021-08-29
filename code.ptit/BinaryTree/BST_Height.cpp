/*
Cho dãy số gồm N số là phép duyệt theo thứ tự trước
(Preorder) của một cây nhị phân tìm kiếm.
Hãy tìm độ sâu của cây ?

Ví dụ với dãy
A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45}
là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả là 3.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

class node {
  public:
    int data, level;
    node *left, *right;

    node(int data, int level) {
        this->data = data;
        this->level = level;
        this->left = this->right = NULL;
    }
};

int height;
void buildBST(node *p, int l, int r) {
    if (l > r || l >= n || r >= n) return;
    int rl = l + 1;
    while (a[rl] < a[l] && rl < n) rl++;
    if (rl < n) {
        int lv = p->level + 1;
        if (l + 1 <= rl - 1) {
            p->left = new node(a[l + 1], lv);
            if (lv > height) height = lv;
            buildBST(p->left, l + 1, rl - 1);
        }
        if (rl <= r) {
            p->right = new node(a[rl], lv);
            if (lv > height) height = lv;
            buildBST(p->right, rl, r);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        height = 0;
        cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        node *root = new node(a[0], 0);
        buildBST(root, 0, n - 1);
        // postOrder(root);

        cout << height << "\n";
    }
    return 0;
}