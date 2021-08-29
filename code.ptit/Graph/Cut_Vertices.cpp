/*

*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010

int v, e, vs[max];
vector<vector<int> > ke;
queue<int> q;

void Init() {
    cin >> v >> e;
    ke.clear();
    ke.resize(v + 5);
    memset(vs, 0, sizeof(vs));
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
}

void BFS(int u) {
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int vv = q.front();
        q.pop();
        for (int i = 0; i < ke[vv].size(); i++) {
            int tmp = ke[vv][i];
            if (!vs[tmp]) {
                q.push(tmp);
                vs[tmp] = 1;
            }
        }
    }
}

int TPLT() {
    int count = 0;
    for (int i = 1; i <= v; i++) {
        if (!vs[i]) {
            BFS(i);
            ++count;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        int k = TPLT();
        // cout << k << "\n";
        for (int i = 1; i <= v; i++) {
            memset(vs, 0, sizeof(vs));
            vs[i] = 1;
            int l = TPLT();
            // cout << l << " ";
            if (l > k)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}