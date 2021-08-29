/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;
#define max 100001
#define ll long

int N, M;

int vs[max];

int len = 0;

struct node {
    int vertex, weight;
};

vector<vector<node> > ke;

vector<int> res;

void DFS(int u) {
    vs[u] = 1;
    if (u == N) {
        res.push_back(len);
        return;
    } else if (u < N) {
        // if (res.size() >= 10) return;
        for (int i = 0; i < ke[u].size(); ++i) {
            node v = ke[u][i];
            int vv = v.vertex;
            if (!vs[vv] && v.weight > 0) {
                int tmp = v.weight;
                v.weight = -1;
                for (int i = 0; i < ke[vv].size(); ++i) {
                    if (ke[vv][i].vertex == u) {
                        ke[vv][i].weight = -1;
                        break;
                    }
                }
                len += tmp;
                vs[vv] = 1;
                DFS(vv);
                v.weight = tmp;
                for (int i = 0; i < ke[vv].size(); ++i) {
                    if (ke[vv][i].vertex == u) {
                        ke[vv][i].weight = tmp;
                        break;
                    }
                }
                vs[vv] = 0;
                len -= tmp;
            }
        }
    }
}

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    // memset(a, 0, sizeof(a));
    res.clear();

    len = 0;
    cin >> N >> M;

    ke.clear();
    ke.resize(N + 5);

    memset(vs, 0, sizeof(vs));
    for (int i = 1; i <= M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        node t1 = {v, c}, t2 = {u, c};
        ke[u].push_back(t1);
        ke[v].push_back(t2);
    }
    DFS(1);
    int dem = 0;
    sort(res.begin(), res.end());
    // for (int i = 0; i < res.size(); ++i) {
    //     cout << res[i] << "\n";
    //     if (res[i] == res[0]) ++dem;
    // }
    int i = 0;
    while (res[i] == res[0]) {
        ++dem;
        ++i;
    }
    cout << res[0] << " " << dem << "\n";
    // }
    return 0;
}
