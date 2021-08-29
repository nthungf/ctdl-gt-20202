/*
 * Cho mảng A[] gồm n phần tử và mảng B[] gồm m phần tử.
 * Nhiệm vụ của bạn là tìm tích giữa phần tử lớn nhất
 * của mảng A[] và phần tử nhỏ nhất của mảng B[].
 * Ví dụ A[] = {5, 7, 112, 9, 3, 6, 2 },
 * B[] = {1, 2, 6, -1, 0, 9} ta có kết quả là -9 = 9*(-1).
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << a[a.size() - 1] * b[0] << "\n";
    }
    return 0;
}