/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh. Sử dụng thuật toán BFS,
hãy kiểm tra xem đồ thị có tồn tại chu trình hay không?
*/

#include <bits/stdc++.h>
using namespace std;

#define max 1010

int v, e, check;
vector<vector<int> > ke;
vector<int> vs, pre;
queue<int> q;

void Clear() {
    check = 0;
    ke.clear();
    ke.resize(v + 10);
    vs.clear();
    vs.resize(v + 10);
    pre.clear();
    pre.resize(v + 10);
    q = queue<int>();
}

void Init() {
    cin >> v >> e;
    Clear();
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
    // cout << u << " ";
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < ke[v].size(); ++i) {
            int x = ke[v][i];
            if (vs[x] && pre[v] != x) {
                check = 1;
                return;
            }
            if (!vs[x]) {
                pre[x] = v;
                q.push(x);
                vs[x] = 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        for (int i = 1; i <= v; i++) {
            // fill(vs.begin(), vs.end(), 0);
            fill(pre.begin(), pre.end(), 0);
            if (!vs[i]) {
                pre[i] = -1;
                BFS(i);
                if (check) {
                    break;
                }
            }
        }
        check ? cout << "YES" : cout << "NO";
        cout << "\n";
    }
    return 0;
}