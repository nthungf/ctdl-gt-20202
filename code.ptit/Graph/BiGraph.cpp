/*
Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh
có thể được chia thành hai tập không giao nhau thỏa mãn
điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập.
Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho
có phải là một đồ thị hai phía hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ke[1010];
int color[1010];
int pre[1010];

void Coloring(int u) {
    queue<int> q;
    q.push(u);
    color[u] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            }
        }
    }
}

bool Check() {
    for (int u = 1; u <= N; u++) {
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i];
            if (color[u] == color[v]) return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 0; i < 1010; i++) ke[i].clear();
        for (int i = 0; i < M; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            ke[v2].push_back(v1);
        }
        memset(color, -1, sizeof(color));
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= N; i++) {
            if (color[i] == -1) Coloring(i);
        }
        // for (int i = 1; i <= N; i++) {
        //     cout << i << " " << color[i] << "\n";
        // }
        if (Check()) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}