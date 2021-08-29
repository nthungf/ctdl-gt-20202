/*
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1.
Bạn hãy tìm hình vuông có kích thước lớn nhất,
sao cho các số trong hình vuông toàn là số 1.
*/

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c) {
    int arr[] = {a, b, c};
    int min = INT_MAX;
    for (int i = 0; i < 3; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > a(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (a[i][j] == 1)
                    a[i][j] += min(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]);
            }
        }
        int maxxx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > maxxx) {
                    maxxx = a[i][j];
                }
                // cout << a[i][j] << " ";
            }
            // cout << '\n';
        }
        cout << maxxx << "\n";
    }
    return 0;
}