/*
Cho đồ thị vô hướng liên thông G=<V, E> được biểu diễn
dưới dạng danh sách cạnh. Sử dụng thuật toán BFS,
hãy đưa ra tất cả các cạnh cầu của đồ thị?
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010

int v, e, k, vs[max];
queue<int> q;
vector<vector<int> > ke;

void Init() {
    k = 0;
    cin >> v >> e;
    ke.clear();
    ke.resize(v + 1);
    memset(vs, 0, sizeof(vs));
    for (int i = 0; i < e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        ke[v1].push_back(v2);
        ke[v2].push_back(v1);
    }
}

void BFS(int u) {
    vs[u] = 1;
    q.push(u);
    // cout << u << " ";
    while (!q.empty()) {
        int vv = q.front();
        q.pop();
        for (int i = 0; i < ke[vv].size(); i++) {
            int vvv = ke[vv][i];
            if (!vs[vvv] && vvv > 0) {
                q.push(vvv);
                vs[vvv] = 1;
            }
        }
    }
}

int tplt_bfs() {
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
        int k = tplt_bfs();
        // cout << k << "\n";
        for (int i = 1; i <= v; i++) {
            for (int j = 0; j < ke[i].size(); j++) {
                int tmp = ke[i][j];
                if (tmp > i) {
                    // xoa canh
                    ke[i][j] = 0;
                    for (int x = 0; x < ke[tmp].size(); x++) {
                        if (ke[tmp][x] == i)
                            ke[tmp][x] = 0;
                    }
                    //

                    memset(vs, 0, sizeof(vs));
                    int l = tplt_bfs();
                    // cout << i << " " << tmp << "\n";
                    // cout << l << "\n";
                    if (l > k) {
                        cout << i << " " << tmp << " ";
                    }

                    // tra lai canh
                    ke[i][j] = tmp;
                    for (int x = 0; x < ke[tmp].size(); x++) {
                        if (ke[tmp][x] == 0)
                            ke[tmp][x] = i;
                    }
                    //
                }
            }
        }
        cout << "\n";
    }
    return 0;
}