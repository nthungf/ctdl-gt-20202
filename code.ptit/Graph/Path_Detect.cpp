/*


Cho đồ thị vô hướng có N đỉnh và M cạnh.
Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa
2 đỉnh x và y có tồn tại đường đi tới nhau hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, Q, k;
vector<int> ke[1010];
int vs[1010];

void DFS(int u) {
    vs[u] = k;
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i];
        if (!vs[v]) DFS(v);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        k = 1;
        memset(vs, 0, sizeof(vs));
        for (int i = 0; i < 1010; i++) ke[i].clear();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            ke[v2].push_back(v1);
        }
        for (int i = 1; i <= N; i++) {
            // cout << i << " ";
            if (!vs[i]) {
                DFS(i);
                k++;
                i = 0;
            }
        }
        cin >> Q;
        while (Q--) {
            int x, y;
            cin >> x >> y;
            if (vs[x] == vs[y]) cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}