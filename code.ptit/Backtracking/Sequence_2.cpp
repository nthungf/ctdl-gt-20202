/*
Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt
của dãy số A[] là tam giác được tạo ra bởi n hàng,
trong đó hàng thứ n là dãy số A[], hàng i là
tổng hai phần tử liên tiếp của hàng i+1 (1≤i≤n-1).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > a(n);
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            a[n - 1].push_back(tmp);
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < a[i + 1].size() - 1; j++) {
                a[i].push_back(a[i + 1][j] + a[i + 1][j + 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << '[';
            for (int j = 0; j < a[i].size() - 1; j++) {
                cout << a[i][j] << " ";
            }
            cout << a[i][a[i].size() - 1] << "] ";
        }
        cout << "\n";
    }
    return 0;
}
