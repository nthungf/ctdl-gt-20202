/*
Cho hai mảng là phép duyệt Inorder và Level-order,
nhiệm vụ của bạn là xây dựng cây nhị phân và đưa ra
kết quả phép duyệt Postorder
*/

#include <bits/stdc++.h>
using namespace std;

struct inl {
    int in;
    int lev;
};
vector<inl> a;

void postOrder(int l, int r) {
    // cout << l << " " << r << "\n";
    int root, root_index, min_lev = 100000;
    for (int i = l; i <= r; i++) {
        if (a[i].lev < min_lev) {
            root = a[i].in;
            root_index = i;
            min_lev = a[i].lev;
        }
    }
    // cout << root_index << "\n";
    if (l <= root_index - 1) postOrder(l, root_index - 1);
    if (root_index + 1 <= r) postOrder(root_index + 1, r);
    cout << root << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].in;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int j = 0; j < n; j++) {
                if (a[j].in == x) {
                    a[j].lev = i;
                    break;
                }
            }
        }
        postOrder(0, n - 1);
        cout << "\n";
    }
    return 0;
}