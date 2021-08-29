/*
Cho dãy số gồm N số là phép duyệt theo thứ tự trước
(Preorder) của một cây nhị phân tìm kiếm.
Hãy in ra tất cả các node lá của cây ?

Ví dụ với dãy
A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45}
là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả:
15, 23, 28, 33, 38, 45.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void preOrder(int l, int r) {
    if (l > r || l >= n || r >= n) return;
    if (l == r) cout << a[l] << " ";
    int lr = l + 1;
    while (lr < n && a[lr] < a[l]) {
        lr++;
    }
    preOrder(l + 1, lr - 1);
    preOrder(lr, r);
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        preOrder(0, n - 1);
        cout << "\n";
    }
    return 0;
}