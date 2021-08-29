/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Hãy tìm số thành phần liên thông của đồ thị
bằng thuật toán BFS.
*/

#include <bits/stdc++.h>
using namespace std;

#define max 1010

int v, e, dem;
int a[max][max], vs[max];
queue<int> q;

void Init() {
    cin >> v >> e;
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    dem = 0;
    q = queue<int>();
    for (int i = 1; i <= e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

void BFS(int u) {
    // cout << u << " ";
    q.push(u);
    vs[u] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= v; i++) {
            if (!vs[i] && a[x][i]) {
                q.push(i);
                vs[i] = 1;
                // cout << i << " ";
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
            if (!vs[i]) {
                BFS(i);
                ++dem;
                // cout << "\n";
            }
        }
        // BFS(1);
        cout << dem << '\n';
    }
    return 0;
}