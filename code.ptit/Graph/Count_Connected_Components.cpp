/*
Cho đồ thị vô hướng G=<V, E> được biểu diễn
dưới dạng danh sách cạnh.
Hãy tìm số thành phần liên thông của đồ thị.
*/

#include <bits/stdc++.h>
using namespace std;

#define max 1010

int v, e, dem;
int a[max][max], vs[max];

void Init() {
    cin >> v >> e;
    memset(a, 0, sizeof(a));
    memset(vs, 0, sizeof(vs));
    dem = 0;
    for (int i = 1; i <= e; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }
}

void DFS(int u) {
    // cout << u << " ";
    vs[u] = 1;
    for (int i = 1; i <= v; i++) {
        if (!vs[i] && a[u][i]) {
            DFS(i);
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
                DFS(i);
                ++dem;
                // cout << "\n";
            }
        }
        cout << dem << '\n';
    }
    return 0;
}