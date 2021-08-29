/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

struct canh {
    int d, c, ts;
};
bool cmp(canh a, canh b) { return a.ts < b.ts; }

int n, m, vs[100], t[100];
canh e[10000];

void Kruskal() {
    sort(e, e + m, cmp);
    int wt = 0, k = 0;
    for (int i = 1; i <= n; ++i) vs[i] = 0;
    for (int i = 0; i < m; ++i) {
        if (!(vs[e[i].d] != 0 && vs[e[i].d] == vs[e[i].c])) {
            k++;
            t[k] = i;
            wt += e[i].ts;
            if (k == n - 1) {
                cout << wt << "\n";
                for (int j = 1; j <= k; ++j) {
                    cout << e[t[j]].d << " " << e[t[j]].c << "\n";
                }
                return;
            }
            int u = e[i].d, v = e[i].c;
            if (!vs[u] && !vs[v]) {
                vs[u] = k;
                vs[v] = k;
            } else if (!vs[u] && vs[v]) {
                vs[u] = vs[v];
            } else if (vs[u] && !vs[v]) {
                vs[v] = vs[u];
            } else if (vs[u] < vs[v]) {
                int tmp = vs[v];
                for (int j = 1; j <= n; j++)
                    if (vs[j] == tmp) vs[j] = vs[u];
            } else if (vs[v] < vs[u]) {
                int tmp = vs[u];
                for (int j = 1; j <= n; j++)
                    if (vs[j] == tmp) vs[j] = vs[v];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> e[i].d >> e[i].c >> e[i].ts;
    }
    Kruskal();
    return 0;
}
