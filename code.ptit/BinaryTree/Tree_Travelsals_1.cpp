/*
Cho phép duyệt cây nhị phân Inorder và Preorder,
hãy đưa ra kết quả phép duyệt Postorder của cây nhị phân.
*/

#include <bits/stdc++.h>
using namespace std;

// pre: root left right
// in: left root right
// post: left right root

vector<int> in, pre, post;

int Search(int p) {
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == p) return i;
    }
    return -1;
}

void postOrder(int lp, int rp, int li, int ri) {
    int root_index = Search(pre[lp]);
    int left_size = root_index - li;
    if (left_size > 0) postOrder(lp + 1, lp + left_size, li, root_index - 1);
    int right_size = ri - root_index;
    if (right_size > 0) postOrder(lp + left_size + 1, rp, root_index + 1, ri);
    cout << pre[lp] << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        in.resize(n);
        pre.resize(n);
        post.clear();
        post.resize(n);
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> pre[i];
        postOrder(0, n - 1, 0, n - 1);
        cout << "\n";
    }
    return 0;
}