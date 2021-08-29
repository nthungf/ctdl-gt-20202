/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, a[100][100], vs[100], d[100], e[100];

void Prim(int s) {
    int v;
    for (v = 1; v <= n; ++v) {
        vs[v] = 0;
        d[v] = a[s][v];
        e[v] = s;
    }
    vs[s] = 1;
    d[s] = 0;
    e[s] = 0;
    int wt = 0, dem = 1;
    while (dem < n) {
        int u = 0, min = 30000;
        for (v = 1; v <= n; ++v) {
            if (vs[v] == 0 && d[v] < min) {
                min = d[v];
                u = v;
            }
        }
        if (u == 0) {
            cout << "Khong co cay khung\n";
            return;
        }
        vs[u] = 1;
        wt += a[u][e[u]];
        for (v = 1; v <= n; ++v) {
            if (vs[v] == 0 && d[v] > a[u][v]) {
                d[v] = a[u][v];
                e[v] = u;
            }
        }
        dem++;
    }
    cout << wt << "\n";
    for (v = 1; v <= n; ++v)
        if (e[v] != 0) cout << v << " " << e[v] << "\n";
    return;
}

int main() {
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v1, v2, ts;
        cin >> v1 >> v2 >> ts;
        a[v1][v2] = ts;
        a[v2][v1] = ts;
    }
    Prim(1);

    return 0;
}
