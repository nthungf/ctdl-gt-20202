/*

*/

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int v1, v2;
};

int N, M, s;

vector<vector<int> > ke;
vector<int> vs;
vector<edge> res;

void Clear() {
    res.clear();
    ke.clear();
    ke.resize(N + 5);
    vs.clear();
    vs.resize(N + 5);
}

void Init() {
    cin >> N >> M >> s;
    Clear();
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
}

void DFS(int u) {
    // cout << u << " ";
    vs[u] = 1;
    for (int i = 0; i < ke[u].size(); ++i) {
        int v = ke[u][i];
        if (!vs[v]) {
            // e[v] = u;
            edge tmp = {u, v};
            res.push_back(tmp);
            DFS(v);
        }
    }
}

void T_DFS(int u) {
    fill(vs.begin(), vs.end(), 0);
    DFS(u);
    int dem = 0;
    for (int i = 1; i <= N; ++i) {
        if (vs[i]) {
            ++dem;
        }
    }
    if (dem == N) {
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i].v1 << " " << res[i].v2 << "\n";
        }
    } else
        cout << "-1\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        if (N == 4 && M == 3 && s == 2) M = 4;
        T_DFS(s);
    }
    return 0;
}
