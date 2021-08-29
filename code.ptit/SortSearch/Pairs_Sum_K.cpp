/*
Cho mảng A[] gồm n phần tử và số k.
Đếm tất cả các cặp phần tử của mảng có tổng bằng k.
Ví dụ A[] = {1, 5, 3, 4, 2 }, k = 7 ta có kết quả
là 2 cặp (3, 4), (5, 2).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int dem = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n && a[i] + a[j] <= k; j++) {
                if (a[i] + a[j] == k)
                    ++dem;
            }
        }
        cout << dem << "\n";
    }
    return 0;
}