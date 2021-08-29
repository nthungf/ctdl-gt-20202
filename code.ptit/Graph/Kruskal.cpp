/*
Cho đồ thị vô hướng có trọng số G=<V, E, W>.
Nhiệm vụ của bạn là hãy xây dựng một cây khung
nhỏ nhất của đồ thị bằng thuật toán Kruskal.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    int first, last;
    int w;
};
bool cmp(edge x, edge y) {
    if (x.w != y.w) return x.w < y.w;
    if (x.first != y.first) return x.first < y.first;
    return x.last < y.last;
}
vector<edge> e;

int V, E;
int vs[1010];
// int res[1010];

void Kruskal() {
    memset(vs, 0, sizeof(vs));
    sort(e.begin(), e.end(), cmp);
    int wt = 0;
    int k = 0;
    for (int i = 0; i < e.size(); i++) {
        if (vs[e[i].first] != vs[e[i].last]) {
            // cout << e[i].first << " " << e[i].last << "\n";
            k++;
            wt += e[i].w;
            if (k == V - 1) {
                cout << wt << "\n";
                return;
            }
            int u = e[i].first, v = e[i].last;
            if (vs[u] == 0 && vs[v] == 0) {
                vs[u] = k;
                vs[v] = k;
            } else if (vs[u] == 0 && vs[v] != 0)
                vs[u] = vs[v];
            else if (vs[u] != 0 && vs[v] == 0)
                vs[v] = vs[u];
            else if (vs[u] < vs[v]) {
                for (int j = 1; j <= V; j++)
                    if (vs[j] == vs[v]) vs[j] = vs[u];
            } else if (vs[v] < vs[u]) {
                for (int j = 1; j <= V; j++)
                    if (vs[j] == vs[u]) vs[j] = vs[v];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        e.clear();
        cin >> V >> E;
        int x, y, z;
        for (int i = 0; i < E; i++) {
            cin >> x >> y >> z;
            // if (x > y) swap(x, y);
            e.push_back({x, y, z});
        }
        Kruskal();
    }
    return 0;
}