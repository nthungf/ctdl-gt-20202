/*
Cho đồ thị có hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh. Sử dụng thuật toán BFS,
hãy kiểm tra xem đồ thị có liên thông mạnh hay không?
*/

#include <bits/stdc++.h>
using namespace std;

#define max 1001

int a[max][max];
int vs[max], E[max];
int v, e, k, ok;
queue<int> q;

void Init() {
    cin >> v >> e;
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    memset(E, 0, sizeof(E));
    ok = 1;
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
    }
}

void BFS(int u) {
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int vv = q.front();
        q.pop();
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
        for (int i = 1; i <= v; i++) {
            k = 0;
            BFS(i);
            for (int i = 1; i <= v; i++) {
                if (vs[i])
                    k++;
            }
            if (k < v) {
                ok = 0;
                break;
            } else if (i == v && k == v) {
                cout << "YES";
            }
        }
        if (!ok) {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}