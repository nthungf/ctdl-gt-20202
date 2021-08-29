/*
Cho một bảng số kích thước N x M.
Chi phí khi đi qua ô (i,j) bằng A[i][j].
Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1)
tới ô (N, M) sao cho chi phí là nhỏ nhất.
Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên
và xuống dưới.
*/

#include <bits/stdc++.h>
using namespace std;

#define max 501

struct cell {
    int x, y, cost;

    bool operator==(const cell &p) { return x == p.x && y == p.y; }
    bool operator!=(const cell &p) { return x != p.x || y != p.y; }
};
bool cmp(cell a, cell b) { return a.cost < b.cost; }

cell a[max][max];
cell pre[max][max];
bool vs[max][max];

int n, m, best;

int xM[] = {-1, 1, 0, 0};
int yM[] = {0, 0, -1, 1};

int isSafe(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m && !vs[x][y]); }

int calcSum() {
    int sum = 0;
    cell tmp = a[n - 1][m - 1];

    while (tmp != a[0][0]) {
        cout << tmp.x << " " << tmp.y << " " << tmp.cost << "\n";
        sum += tmp.cost;
        tmp = pre[tmp.x][tmp.y];
    }
    // cout << "\n";
    return sum;
}

void Try(cell u) {
    if (u == a[n - 1][m - 1]) {
        int sum = calcSum();
        if (sum < best) best = sum;
        return;
    }
    vector<cell> nexts;
    for (int i = 0; i < 4; i++) {
        int xN = u.x + xM[i];
        int yN = u.y + yM[i];
        if (isSafe(xN, yN)) {
            nexts.push_back(a[xN][yN]);
        }
    }
    sort(nexts.begin(), nexts.end(), cmp);

    for (int i = 0; i < nexts.size(); i++) {
        vs[nexts[i].x][nexts[i].y] = true;
        pre[nexts[i].x][nexts[i].y] = u;
        Try(nexts[i]);
        vs[nexts[i].x][nexts[i].y] = true;
        pre[nexts[i].x][nexts[i].y] = {0, 0, 0};
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        best = INT_MAX;
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j].x = i;
                a[i][j].y = j;
                cin >> a[i][j].cost;
            }
        }
        Try(a[0][0]);
        cout << best << "\n";
    }
    return 0;
}