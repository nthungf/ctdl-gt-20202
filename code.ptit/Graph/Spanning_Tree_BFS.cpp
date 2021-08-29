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

queue<int> q;
void BFS(int u) {
    vs[u] = 1;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (!vs[x]) {
                q.push(x);
                vs[x] = 1;
                edge tmp = {v, x};
                res.push_back(tmp);
            }
        }
    }
}

void T_BFS(int u) {
    fill(vs.begin(), vs.end(), 0);
    BFS(u);
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
        T_BFS(s);
    }
    return 0;
}
