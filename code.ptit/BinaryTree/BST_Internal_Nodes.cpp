/*
Cho dãy số gồm N số là phép duyệt theo thứ tự trước
(Preorder) của một cây nhị phân tìm kiếm.
Hãy đưa ra số các node trung gian của cây ?

Ví dụ với dãy
A[] = {30, 20, 15, 25, 23, 28, 40, 35, 33, 38, 45}
là phép duyệt cây theo thứ tự trước sẽ cho ta kết quả
là 5 bao gồm các node: 30, 20, 25, 40, 35.
*/

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int dem;

void preOrder(int l, int r) {
    if (l > r || l >= n || r >= n) return;
    if (l < r) ++dem;
    int lr = l + 1;
    while (lr < n && a[lr] < a[l]) lr++;
    preOrder(l + 1, lr - 1);
    preOrder(lr, r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        dem = 0;
        preOrder(0, n - 1);
        cout << dem << "\n";
    }
    return 0;
}