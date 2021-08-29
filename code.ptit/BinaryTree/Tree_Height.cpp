/*

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ke[100010];

int height, level;

void DFS(int u) {
    if (level > height) height = level;
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i];
        level++;
        DFS(v);
        level--;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        height = 0;
        level = 0;
        for (int i = 0; i < 100010; i++) ke[i].clear();
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
        }
        DFS(1);
        cout << height << "\n";
    }
    return 0;
}