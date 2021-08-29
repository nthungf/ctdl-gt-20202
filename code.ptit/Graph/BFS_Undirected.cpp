/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Hãy viết thuật toán duyệt theo chiều rộng
bắt đầu tại đỉnh uÎV (BFS(u)=?)
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010

int v, e, u;

int a[max][max], vs[max], E[max];
queue<int> q;

void Init() {
    cin >> v >> e >> u;
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

void Bfs(int u) {
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int vv = q.front();
        q.pop();
        cout << vv << " ";
        for (int i = 1; i <= v; i++) {
            if (!vs[i] && a[vv][i]) {
                q.push(i);
                vs[i] = 1;
                E[i] = vv;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Bfs(u);
        cout << "\n";
    }
    return 0;
}