/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Sử dụng thuật toán DFS, hãy kiểm tra xem đồ thị
có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int> > ke;
vector<int> vs, pre;

void Clear() {
    ke.clear();
    ke.resize(V + 5);
    vs.clear();
    vs.resize(V + 5);
    pre.clear();
    pre.resize(V + 5);
}

void Init() {
    cin >> V >> E;
    Clear();
    for (int i = 0; i < E; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
}

int DFS_Cycle(int u) {
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); ++i) {
        int v = ke[u][i];
        if (vs[v] && pre[u] != v) {
            return 1;
        }
        if (!vs[v]) {
            pre[v] = u;
            DFS_Cycle(v);
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        int check = 0;
        for (int i = 1; i <= V; ++i) {
            // fill(vs.begin(), vs.end(), 0);
            fill(pre.begin(), pre.end(), 0);
            if (!vs[i]) {
                pre[i] = -1;
                if (DFS_Cycle(i)) {
                    check = 1;
                    break;
                }
            }
        }
        check ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
