/*
Cho bảng A[] kích thước N x M (N hàng, M cột).
Bạn được phép đi xuống dưới, đi sang phải
và đi xuống ô chéo dưới. Khi đi qua ô (i, j),
điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho
tổng điểm là nhỏ nhất.
*/

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c) {
    int arr[] = {a, b, c};
    int min = INT_MAX;
    for (int i = 0; i < 3; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
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
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if (i == 1) {
                    a[i][j] += a[i][j - 1];
                } else if (j == 1) {
                    a[i][j] += a[i - 1][j];
                } else
                    a[i][j] += min(a[i - 1][j], a[i][j - 1], a[i - 1][j - 1]);
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        cout << a[n][m] << "\n";
    }
    return 0;
}