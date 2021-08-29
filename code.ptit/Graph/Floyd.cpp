/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

#define max 105

int N, M, Q;

int a[max][max], d[max][max], e[max][max];

void Floyd() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            d[i][j] = a[i][j];
            e[i][j] = i;
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    e[i][j] = k;
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    cin >> N >> M;
    memset(d, 0, sizeof(d));
    memset(e, 0, sizeof(e));
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < max; ++j) {
            a[i][j] = INT_MAX / 2;
            if (i == j) a[i][j] = 0;
        }
    }
    for (int i = 0; i < M; ++i) {
        int v1, v2, c;
        cin >> v1 >> v2 >> c;
        a[v1][v2] = c;
        a[v2][v1] = c;
    }
    Floyd();
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << "\n";
    }
    // }
    return 0;
}
