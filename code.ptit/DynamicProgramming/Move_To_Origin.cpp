/*
Giả sử bạn đang ở điểm có tọa độ nguyên dương (n,m)
và cần dịch chuyển về tọa độ (0,0).
Mỗi bước dịch chuyển bạn chỉ được phép dịch chuyển đến
tọa độ (n-1, m) hoặc (n, m-1);
Từ ô (0,m), hoặc (n, 0) thì có thể di chuyển 1 bước để về gốc (0,0).
Hãy đếm số cách bạn có thể dịch chuyển về tọa độ (0,0).
*/

#include <bits/stdc++.h>
using namespace std;
#define max 28

long long a[max][max] = {};

void Solve() {
    for (int i = 1; i < max; i++) {
        a[i][1] = 1;
        a[1][i] = 1;
    }
    for (int i = 2; i < max; i++) {
        for (int j = 2; j < max; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
}

int main() {
    int t;
    cin >> t;
    Solve();
    while (t--) {
        int n, m; // n hang, m cot
        cin >> n >> m;
        cout << a[n + 1][m + 1] << "\n";
    }
    return 0;
}