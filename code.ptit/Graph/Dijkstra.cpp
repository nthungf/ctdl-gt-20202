/*
Cho đồ thị có trọng số không âm G=<V, E> được
biểu diễn dưới dạng danh sách cạnh trọng số.
Hãy viết chương trình tìm đường đi ngắn nhất từ
đỉnh u đến tất cả các đỉnh còn lại trên đồ thị.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 1010
#define maxx INT_MAX

int a[max][max], d[max], vs[max], pre[max];
int v, e, u;

void Init() {
    cin >> v >> e >> u;
    memset(d, 0, sizeof(d));
    memset(vs, 0, sizeof(vs));
    memset(a, 0, sizeof(a));
    memset(pre, 0, sizeof(pre));
    for (int i = 0; i <= v; i++) {
        d[i] = maxx;
        for (int j = 0; j <= v; j++) {
            a[i][j] = maxx;
        }
    }

    int v1, v2, c;
    for (int i = 0; i < e; i++) {
        cin >> v1 >> v2 >> c;
        if (c < a[v1][v2] || a[v1][v2] == maxx) {
            a[v1][v2] = c;
            a[v2][v1] = c;
        }
    }
}

void Output() {
    for (int i = 1; i <= v; i++) cout << d[i] << " ";
    cout << "\n";
}

void Dijkstra() {
    for (int i = 1; i <= v; i++) {
        d[i] = a[u][i];
        pre[i] = u;
    }
    d[u] = 0;
    pre[u] = -1;
    vs[u] = 1;
    while (1) {
        int min = maxx;
        int min_idx = -1;
        for (int i = 1; i <= v; i++) {
            if (!vs[i] && d[i] < min) {
                min = d[i];
                min_idx = i;
            }
        }
        if (min_idx == -1) return;
        vs[min_idx] = 1;
        for (int i = 1; i <= v; i++) {
            int new_d = d[min_idx] + a[min_idx][i];
            if (d[min_idx] == maxx || a[min_idx][i] == maxx) new_d = maxx;
            if (!vs[i] && d[i] > new_d) {
                pre[i] = min_idx;
                d[i] = new_d;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        Init();
        Dijkstra();
        Output();
    }
    return 0;
}