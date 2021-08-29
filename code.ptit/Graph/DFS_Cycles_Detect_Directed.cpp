/*
Cho đồ thị có hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Sử dụng thuật toán DFS, hãy kiểm tra xem đồ thị
có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int V, E, check;
vector<int> ke[1010];
int vs[1010];

void Clear() {
    check = 0;
    memset(vs, 0, sizeof(vs));

    for (int i = 0; i < 1010; ++i) {
        ke[i].clear();
    }
}

void Init() {
    cin >> V >> E;
    Clear();
    for (int i = 0; i < E; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        // ke[v2].push_back(v1);
    }
}

void DFS_Cycle(int u, int x) {
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); ++i) {
        int v = ke[u][i];
        if (!vs[v]) {
            DFS_Cycle(v, x);
        } else if (v == x) {
            check = 1;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 1; i <= V; ++i) {
            memset(vs, 0, sizeof(vs));
            DFS_Cycle(i, i);
            if (check) {
                break;
            }
            // }
        }
        check ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
