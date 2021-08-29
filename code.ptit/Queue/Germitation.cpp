/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int> > a;

void Init() {
    cin >> R >> C;
    a.clear();
    a.resize(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> a[i][j];
        }
    }
}

int isSafe(int x, int y) { return (0 <= x && x < R && 0 <= y && y < C); }

int unDone() {
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (a[i][j] == 1) return 1;
        }
    }
    return 0;
}

int isDelim(pair<int, int> x) { return (x.first == -1 && x.second == -1); }

void Solve() {
    queue<pair<int, int> > q;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (a[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }
    q.push(make_pair(-1, -1));
    int dem = 0;
    while (!q.empty()) {
        // pair<int, int> v = q.front();
        // q.pop();

        int x, y, ok = 0;

        while (!isDelim(q.front())) {
            pair<int, int> v = q.front();
            q.pop();
            // left
            x = v.first;
            y = v.second - 1;
            if (isSafe(x, y) && a[x][y] == 1) {
                if (!ok) {
                    ++dem;
                    ok = 1;
                }
                a[x][y] = 2;
                q.push(make_pair(x, y));
            }
            // up
            x = v.first - 1;
            y = v.second;
            if (isSafe(x, y) && a[x][y] == 1) {
                if (!ok) {
                    ++dem;
                    ok = 1;
                }
                a[x][y] = 2;
                q.push(make_pair(x, y));
            }
            // right
            x = v.first;
            y = v.second + 1;
            if (isSafe(x, y) && a[x][y] == 1) {
                if (!ok) {
                    ++dem;
                    ok = 1;
                }
                a[x][y] = 2;
                q.push(make_pair(x, y));
            }
            // down
            x = v.first + 1;
            y = v.second;
            if (isSafe(x, y) && a[x][y] == 1) {
                if (!ok) {
                    ++dem;
                    ok = 1;
                }
                a[x][y] = 2;
                q.push(make_pair(x, y));
            }
        }
        q.pop();
        if (!q.empty()) {
            q.push(make_pair(-1, -1));
        }
    }
    if (unDone()) cout << "-1\n";
    else
        cout << dem << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Solve();
    }
    return 0;
}