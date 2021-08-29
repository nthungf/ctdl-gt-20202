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
int xMove[] = {1, 0};
int yMove[] = {0, 1};

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

int isSafe(int x, int y) {
    return (x < m && y < n && x >= 0 && y >= 0 && a[x][y] > 0);
}

void Try(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        ++dem;
        return;
    }
    for (int i = 0; i < 2; i++) {
        int nextX = x + xMove[i];
        int nextY = y + yMove[i];
        if (isSafe(nextX, nextY)) {
            Try(nextX, nextY);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Try(0, 0);
        cout << dem << '\n';
    }
    return 0;
}