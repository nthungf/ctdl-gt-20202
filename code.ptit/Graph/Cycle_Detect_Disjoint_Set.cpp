/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Sử dụng Disjoin Set, hãy kiểm tra xem đồ thị
có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> ke[1010];

class DisjointSet {
  public:
    vector<int> pre;

    DisjointSet() {
        pre.resize(V + 1);
        for (int i = 1; i <= V; i++) {
            pre[i] = i;
        }
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
    for (int u = 1; u <= V; u++) {
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i];
            int x = djs.Find(u);
            int y = djs.Find(v);
            // cout << u << "-" << x << " " << v << "-" << y << "\n";
            if (x == y) return true;
            else
                djs.Union(x, y);
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1010; i++) ke[i].clear();
        cin >> V >> E;
        int v1, v2;
        for (int i = 0; i < E; i++) {
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            // ke[v2].push_back(v1);
        }
        if (Detect()) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}