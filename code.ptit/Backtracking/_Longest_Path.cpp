/*
Cho đồ thị vô hướng có N đỉnh và M cạnh.
Bạn hãy tìm đường đi dài nhất trên đồ thị,
sao cho mỗi cạnh chỉ được đi qua nhiều nhất 1 lần.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 30

int a[max][max], vs[max];

int n, m;

void Init() {
    cin >> n >> m;
    memset(a, 0, max * max);
    memset(vs, 0, max);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

void DFS(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int v = 0; v < n; v++) {
        if (!vs[v] && a[u][v]) {
            DFS(v);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        DFS(0);
        cout << "\n";
    }
    return 0;
}