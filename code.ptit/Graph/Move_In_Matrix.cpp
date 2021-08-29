/*
Cho một bảng số kích thước N x M.
Chi phí khi đi qua ô (i,j) bằng A[i][j].
Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1)
tới ô (N, M) sao cho chi phí là nhỏ nhất.
Tại mỗi ô, bạn được phép đi sang trái, sang phải,
đi lên trên và xuống dưới.
*/

#include <bits/stdc++.h>
using namespace std;

#define max 501

int a[max][max], vs[max][max];

int n, m, best, sum;

int xMove[] = {-1, 1, 0, 0};
int yMove[] = {0, 0, -1, 1};

int isSafe(int x, int y) {
    if (vs[x][y] || x < 0 || y < 0 || x >= n || y >= m) return 0;
    return 1;
}

void Try(int x, int y) {
    // cout << sum << "\n";
    if (x == n - 1 && y == m - 1) {
        if (sum < best) {
            best = sum;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextX = x + xMove[i];
        int nextY = y + yMove[i];
        if (isSafe(nextX, nextY)) {
            sum += a[nextX][nextY];
            vs[nextX][nextY] = 1;
            Try(nextX, nextY);
            sum -= a[nextX][nextY];
            vs[nextX][nextY] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        best = INT_MAX;
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        sum = a[0][0];
        Try(0, 0);
        cout << best << "\n";
    }
    return 0;
}