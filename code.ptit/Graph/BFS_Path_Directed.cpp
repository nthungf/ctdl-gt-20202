/*

*/

#include <bits/stdc++.h>
using namespace std;

int V, E, s, t;

vector<int> ke[1010];
int vs[1010], pre[1010];

void BFS() {
    queue<int> q;
    q.push(s);
    vs[s] = 1;
    // cout << s << " ";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < ke[u].size(); i++) {
            int v = ke[u][i];
            if (!vs[v]) {
                // cout << v << " ";
                q.push(v);
                vs[v] = 1;
                pre[v] = u;
            }
        }
    }
}

void path() {
    int x = t;
    vector<int> res;
    while (x != s) {
        // cout << x << " ";
        res.push_back(x);
        x = pre[x];
    }
    res.push_back(s);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        for (int i = 0; i < 1010; i++) ke[i].clear();
        memset(vs, 0, sizeof(vs));
        memset(pre, 0, sizeof(pre));
        cin >> V >> E >> s >> t;
        for (int i = 0; i < E; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
        }
        BFS();
        if (vs[t]) path();
        else
            cout << "-1";
        cout << "\n";
    }
    return 0;
}