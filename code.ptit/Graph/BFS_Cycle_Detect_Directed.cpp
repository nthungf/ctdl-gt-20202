/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh. Sử dụng thuật toán BFS,
hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int v, e, check;
vector<int> ke[1010];
int vs[1010];
queue<int> q;

void Clear() {
    check = 0;
    for (int i = 0; i < 1010; ++i) {
        ke[i].clear();
    }
    q = queue<int>();
}

void Init() {
    cin >> v >> e;
    Clear();
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        // ke[v2].push_back(v1);
    }
}

void BFS(int u) {
    q.push(u);
    vs[u] = 1;
    // cout << u << " ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (!vs[x]) {
                q.push(x);
                vs[x] = 1;
            } else if (x == u) {
                check = 1;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 1; i <= v; i++) {
            memset(vs, 0, sizeof(vs));
            // if (!vs[i]) {
            BFS(i);
            if (check) {
                break;
            }
            // }
        }
        check ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}