/*

*/

#include <bits/stdc++.h>
using namespace std;

int V, E, M;
vector<int> ke[20];

int color[20];

bool Check(int u, int c) {
    for (int i = 0; i < ke[u].size(); i++) {
        int v = ke[u][i];
        if (c == color[v]) return false;
    }
    return true;
}

// chon mau c cho dinh u
bool Try(int u) {
    if (u == V + 1) return true;
    for (int c = 1; c <= M; c++) {
        if (Check(u, c)) {
            color[u] = c;
            Try(u + 1);
            if (Try(u + 1)) return true;
            color[u] = 0;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E >> M;
        memset(color, 0, sizeof(color));
        for (int i = 0; i < 20; i++) ke[i].clear();

        for (int i = 0; i < E; i++) {
            int v1, v2;
            cin >> v1 >> v2;
            ke[v1].push_back(v2);
            ke[v2].push_back(v1);
        }
        if (Try(1)) cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}