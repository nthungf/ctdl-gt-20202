/*
Cho một cây có N node, gốc tại 1.
Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm khoảng cách
giữa hai node u và v.
*/

#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> ke[1010];
int vs[1010];

void BFS(int start, int end) {
    memset(vs, 0, sizeof(vs));
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == end) break;
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i];
            if (!vs[v]) {
                q.push(v);
                vs[v] = vs[u] + 1;
            }
        }
    }
    cout << vs[end] << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        int v1, v2;
        for (int i = 0; i < 1010; i++) ke[i].clear();

        for (int i = 1; i < N; i++) {
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            ke[v2].push_back(v1);
        }
        cin >> Q;
        while (Q--) {
            cin >> v1 >> v2;
            BFS(v1, v2);
        }
    }
    return 0;
}