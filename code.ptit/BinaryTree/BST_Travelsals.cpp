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

void postOrder(int l, int r) {
    if (l > r || l >= n || r >= n) return;
    int root = a[l];
    int lr = l + 1;
    while (a[lr] < root) lr++;
    lr--;
    postOrder(l + 1, lr);
    postOrder(lr + 1, r);
    cout << root << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.clear();
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        postOrder(0, n - 1);
        cout << "\n";
    }
    return 0;
}