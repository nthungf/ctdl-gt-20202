/*

*/

#include <bits/stdc++.h>
using namespace std;

int V, E, s;

vector<int> ke[1010];
int vs[1010];

void DFS(int u) {
    cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i];
        if (!vs[v]) DFS(v);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1010; i++) ke[i].clear();
        memset(vs, 0, sizeof(vs));
        cin >> V >> E >> s;
        for (int i = 0; i < E; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
        }
        DFS(s);
        cout << "\n";
    }
    return 0;
}