/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Hãy tìm đường đi từ đỉnh s đến đỉnh t
trên đồ thị bằng thuật toán DFS.
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > a;
vector<int> vs, res, E, ress;

int v, e, s, t;

void Init() {
    cin >> v >> e >> s >> t;
    a.clear();
    a.resize(v + 5, vector<int>(v + 5));
    vs.clear();
    vs.resize(v + 5);
    res.clear();
    ress.clear();
    E.clear();
    E.resize(v + 5);
    for (int i = 1; i <= e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

// dinh dau x, dinh cuoi y
void DFS(int x) {
    // cout << x << " ";
    res.push_back(x);
    vs[x] = 1;
    for (int y = 1; y <= v; y++) {
        if (!vs[y] && a[x][y]) {
            E[y] = x;
            DFS(y);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Init();
        DFS(s);
        if (vs[t]) {
            int xx = t;
            while (xx > 0) {
                // cout << xx << " ";
                ress.push_back(xx);
                xx = E[xx]; // E[xx] la dinh di den xx
            }

            for (int i = ress.size() - 1; i >= 0; i--) {
                cout << ress[i] << " ";
            }

        } else
            cout << "-1";
        cout << "\n";
    }
    return 0;
}