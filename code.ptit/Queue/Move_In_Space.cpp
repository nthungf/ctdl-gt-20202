/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

#define max 35

int A, B, C;

char a[max][max][max];

int vs[max][max][max];

int xM[] = {-1, 1, 0, 0, 0, 0};
int yM[] = {0, 0, -1, 1, 0, 0};
int zM[] = {0, 0, 0, 0, -1, 1};

struct position {
    int x, y, z;
    bool operator==(const position &p1) { return (p1.x == x && p1.y == y && p1.z == z); }
};

position s, e;

position pre[max][max][max];

int isSafe(position p) {
    return (p.x >= 0 && p.x < A && p.y >= 0 && p.y < B && p.z >= 0 && p.z < C &&
            a[p.x][p.y][p.z] != '#');
}

void BFS(position s) {
    queue<position> q;
    q.push(s);
    vs[s.x][s.y][s.z] = 1;
    int ok = 1;
    while (!q.empty()) {
        position vv = q.front();
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int xN = vv.x + xM[i];
            int yN = vv.y + yM[i];
            int zN = vv.z + zM[i];
            position tmp = {xN, yN, zN};
            if (isSafe(tmp) && !vs[xN][yN][zN]) {
                // cout << xN << " " << yN << " " << zN << "\n";
                q.push(tmp);
                vs[xN][yN][zN] = 1;
                pre[xN][yN][zN] = vv;
                // ++dem;
                if (tmp == e) {
                    ok = 0;
                    break;
                }
            }
        }
        if (!ok) break;
    }
    if (!ok) {
        int dem = 0;
        position temp = e;
        while (!(temp == s)) {
            temp = pre[temp.x][temp.y][temp.z];
            ++dem;
        }
        cout << dem << "\n";
    } else
        cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> A >> B >> C;
        memset(a, 0, sizeof(a));
        memset(vs, 0, sizeof(vs));
        memset(pre, 0, sizeof(pre));
        for (int i = 0; i < A; ++i) {
            for (int j = 0; j < B; ++j) {
                for (int k = 0; k < C; ++k) {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S') {
                        s = {i, j, k};
                    }
                    if (a[i][j][k] == 'E') {
                        e = {i, j, k};
                    }
                }
            }
        }
        // cout << s.x << " " << s.y << " " << s.z << "\n";
        // cout << e.x << " " << e.y << " " << e.z << "\n";
        BFS(s);
    }
    return 0;
}
