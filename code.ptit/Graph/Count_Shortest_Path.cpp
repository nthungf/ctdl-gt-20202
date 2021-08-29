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

vector<int> res;

void DFS(int u, int **a) {
    vs[u] = 1;
    if (u == N) {
        res.push_back(len);
        return;
    } else if (u < N) {
        // if (res.size() >= 10) return;
        for (int v = 1; v <= N; ++v) {
            if (!vs[v] && a[u][v] > 0) {
                int tmp = a[u][v];
                a[u][v] = -1;
                len += tmp;
                vs[v] = 1;
                DFS(v, a);
                a[u][v] = tmp;
                vs[v] = 0;
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
    memset(vs, 0, sizeof(vs));
    res.clear();
    len = 0;
    cin >> N >> M;

    int **a = new int *[N + 5];
    for (int i = 0; i < N + 5; ++i) {
        a[i] = new int[N + 5];
    }
    for (int i = 1; i <= N; ++i) {
        vs[i] = 0;
        for (int j = 0; j <= N; ++j) {
            a[i][j] = -1;
        }
    }
    for (int i = 1; i <= M; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }
    DFS(1, a);
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
