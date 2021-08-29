/*
Cho ma trận A[M][N]. Nhiệm vụ của bạn là đếm tất cả
các đường đi từ phần tử A[0][0] đến phần tử A[M-1][N-1].
Bạn chỉ được phép dịch chuyển xuống dưới hoặc sang phải
phần tử liền kề với vị trí hiện tại.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 120

int m, n, dem;
int a[max][max];
int b[max][max];
void Init() {
    dem = 0;
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}

void Solve() {
    for (int i = 1; i <= 100; i++) {
        b[1][i] = 1;
        b[i][1] = 1;
    }
    for (int i = 2; i <= 100; i++) {
        for (int j = 2; j <= 100; j++) {
            b[i][j] = b[i - 1][j] + b[i][j - 1];
        }
    }
}

int main() {
    int t;
    cin >> t;
    Solve();
    while (t--) {
        Init();
        cout << b[m][n] << "\n";
    }
    return 0;
}