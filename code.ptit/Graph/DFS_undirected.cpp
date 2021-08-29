/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng
danh sách cạnh. Hãy viết thuật toán duyệt theo chiều sâu
bắt đầu tại đỉnh uÎV (DFS(u)=?)
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010

int v, e, u;

// int a[max][max], vs[max];
vector<vector<int> > a;
vector<int> vs;

void Dfs(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int i = 1; i <= v; i++) {
        if (a[u][i] == 1 && !vs[i]) {
            // E.push_back(u);
            Dfs(i);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e >> u;
        a.clear();
        vs.clear();
        a.resize(v + 5, vector<int>(v + 5));
        vs.resize(v + 5);

        for (int i = 1; i <= e; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            a[v1][v2] = 1;
            a[v2][v1] = 1;
        }
        Dfs(u);
        // for (int i = 0; i < E.size(); i++) {
        //     cout << E[i] << " ";
        // }
        cout << "\n";
    }
    return 0;
}