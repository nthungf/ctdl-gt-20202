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

int height;
void preOrder(int l, int r, int h) {
    if (l > r || l >= n || r >= n) return;

    if (h > height) height = h;

    int root = a[l];

    int rl = l + 1;

    while (a[rl] < root) rl++;

    if (rl < n) {
        if (l + 1 <= rl - 1) {
            preOrder(l + 1, rl - 1, h + 1);
        }
        if (rl <= r) {
            preOrder(rl, r, h + 1);
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
        preOrder(0, n - 1, 0);
        cout << height << "\n";
    }
    return 0;
}