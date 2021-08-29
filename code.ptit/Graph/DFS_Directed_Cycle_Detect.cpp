/*
Cho đồ thị có hướng G=<V, E> được
biểu diễn dưới dạng danh sách cạnh.
Sử dụng thuật toán DFS, hãy kiểm tra xem
đồ thị có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int v, e, check;
vector<vector<int> > ke;
vector<int> vs, pre;

void Init() {
    cin >> v >> e;
    check = 0;
    ke.clear();
    ke.resize(v + 10);
    vs.clear();
    vs.resize(v + 10);
    pre.clear();
    pre.resize(v + 10);
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
    }
}

void DFS(int u) {
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); ++i) {
        int x = ke[u][i];
        if (vs[x]) {
            if (x != pre[u]) {
            	cout << x << " " << u << " " << pre[u] << "\n";
                check = 1;
                return;
            }
        } else {
            pre[x] = u;
            DFS(x);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 1; i <= v; ++i) {
            fill(vs.begin(), vs.end(), 0);
            cout << i << "\n";
            DFS(i);
            if (check) break;
        }
        if (check) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
