/*
Một đồ thị N đỉnh là một cây, nếu như nó
có đúng N-1 cạnh và giữa 2 đỉnh bất kì,
chỉ tồn tại duy nhất 1 đường đi giữa chúng.

Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra
đồ thị đã cho có phải là một cây hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> ke[1010];
int vs[1010];

void Init() {
    for (int i = 0; i < 1010; ++i) {
        ke[i].clear();
    }
    memset(vs, 0, sizeof(vs));
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
}

void BFS(int u) {
    queue<int> q;
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (!vs[x]) {
                q.push(x);
                vs[x] = 1;
            }
        }
    }
}

void Check() {
    int dem = 0;
    for (int i = 1; i <= N; ++i) {
        if (vs[i]) ++dem;
    }
    if (dem == N) cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        BFS(1);
        Check();
    }
    return 0;
}
