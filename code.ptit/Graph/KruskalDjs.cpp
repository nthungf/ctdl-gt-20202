/*
Cho đồ thị vô hướng có trọng số G=<V, E, W>.
Nhiệm vụ của bạn là hãy xây dựng một cây khung
nhỏ nhất của đồ thị bằng thuật toán Kruskal.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    int s, d, w;
};

bool cmp(edge x, edge y) {
    if (x.w != y.w) return x.w < y.w;
    if (x.s != y.s) return x.s < y.s;
    return x.d < y.d;
}
int V, E, wt;
int vs[1010];
deque<edge> e;
vector<edge> Tree;
// int res[1010];

class DisjointSet {
  public:
    vector<int> pre;

    DisjointSet() {
        pre.resize(V + 1);
        for (int i = 1; i <= V; i++) pre[i] = i;
    }

    int Find(int p) {
        if (pre[p] == p) return p;
        else {
            int res = Find(pre[p]);
            pre[p] = res;
            return res;
        }
    }

    void Union(int a, int b) {
        int x = Find(a);
        int y = Find(b);
        pre[x] = y;
    }
};

bool Detect() {
    DisjointSet djs;
    for (int i = 0; i < Tree.size(); i++) {
        int u = Tree[i].s, v = Tree[i].d;
        int x = djs.Find(u), y = djs.Find(v);
        if (x == y) return true;
        else
            djs.Union(x, y);
    }
    return false;
}

void Kruskal() {
    sort(e.begin(), e.end(), cmp);
    while (!e.empty() && Tree.size() < V - 1) {
        edge x = e.front();
        Tree.push_back(x);
        e.pop_front();
        if (!Detect()) wt += x.w;
        else
            Tree.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        e.clear();
        Tree.clear();
        wt = 0;
        cin >> V >> E;
        int x, y, z;
        for (int i = 0; i < E; i++) {
            cin >> x >> y >> z;
            e.push_back({x, y, z});
        }
        Kruskal();
        cout << wt << "\n";
    }
    return 0;
}