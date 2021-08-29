/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, dem, maxx;
vector<vector<int> > ke;
vector<int> vs;

void Init() {
    cin >> N >> M;
    ke.clear();
    ke.resize(N + 1);
    vs.clear();
    vs.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
    maxx = 0;
}

queue<int> q;
void BFS(int u) {
    vs[u] = 1;
    q.push(u);
    ++dem;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (!vs[x]) {
                q.push(x);
                vs[x] = 1;
                ++dem;
            }
        }
    }
}

void Largest_Group() {
    for (int i = 1; i <= N; ++i) {
        if (!vs[i]) {
            dem = 0;
            BFS(i);
            if (dem > maxx) maxx = dem;
        }
    }
    cout << maxx << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Largest_Group();
    }
    return 0;
}
