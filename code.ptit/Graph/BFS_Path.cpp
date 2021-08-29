/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng
danh sách cạnh. Hãy tìm đường đi từ đỉnh s đến đỉnh t
trên đồ thị bằng thuật toán BFS.
*/

#include <bits/stdc++.h>
using namespace std;

int v, e, s, t;

vector<vector<int> > a;
vector<int> vs, res, ress;
queue<int> q;

void Init() {
    cin >> v >> e >> s >> t;
    a.clear();
    a.resize(v + 5, vector<int>(v + 5));
    vs.clear();
    vs.resize(v + 5);
    res.clear();
    res.resize(v + 5);
    ress.clear();
    int v1, v2;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

void BFS(int u) {
    // if (vs[t])
    //     return;
    q.push(u);
    vs[u] = 1;
    // cout << u << " ";
    while (!q.empty()) {
        int vv = q.front();
        q.pop();
        for (int i = 1; i <= v; i++) {
            if (!vs[i] && a[vv][i]) {
                q.push(i);
                vs[i] = 1;
                res[i] = vv;
                // res.push_back(vv);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Init();
        BFS(s);
        if (vs[t]) {
            while (t > 0) {
                // cout << t << " ";
                ress.push_back(t);
                t = res[t];
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