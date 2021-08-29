/*
Cho đồ thị có trọng số G=<V, E> được biểu diễn
dưới dạng danh sách cạnh trọng số âm hoặc dương.
Hãy viết chương trình xác định xem đồ thị
có chu trình âm hay không.
*/

#include <bits/stdc++.h>
using namespace std;

struct data {
    int vtx, wgt;
};

int vs[1010];
int pre[1010];
vector<data> ke[1010];
int V, E, wt;
vector<int> res;

bool DFS(int u) {
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i].vtx;
        int w = ke[u][i].wgt;
        if (vs[v] && pre[u] != v) {
            res.push_back(wt);
            cout << wt << "\n";
            return true;
        }
        if (!vs[v]) {
            pre[v] = u;
            DFS(v);
            wt -= w;
        }
    }
    return false;
}

bool Check() {
    for (int i = 0; i < res.size(); i++) {
        if (res[i] < 0) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {

        for (int i = 0; i < 1010; i++) {
            ke[i].clear();
        }

        cin >> V >> E;
        int x, y, z;
        for (int i = 0; i < E; i++) {
            cin >> x >> y >> z;
            ke[x].push_back({y, z});
            ke[y].push_back({x, z});
        }
        bool ok = false;
        for (int i = 1; i <= V; i++) {
            memset(vs, 0, sizeof(vs));
            memset(pre, 0, sizeof(pre));
            res.clear();
            wt = 0;
            if (DFS(i) && Check()) {
                ok = true;
                break;
            }
        }
        if (ok) cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}