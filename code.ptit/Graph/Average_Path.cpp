/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

#define max 105

int N, M;

int a[max][max], d[max][max];

void Floyd() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            d[i][j] = a[i][j];
        }
    }
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> M;
        memset(d, 0, sizeof(d));
        memset(a, 0, sizeof(a));
        for (int i = 0; i < max; ++i) {
            for (int j = 0; j < max; ++j) {
                a[i][j] = INT_MAX / 2;
                if (i == j) a[i][j] = 0;
            }
        }
        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            a[u][v] = 1;
        }
        Floyd();
        int sum = 0, dem = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (d[i][j] > 0 && d[i][j] < INT_MAX / 2) {
                    // cout << d[i][j] << " ";
                    sum += d[i][j];
                    dem++;
                }
            }
        }
        float res = (float)sum / dem;
        cout << fixed << setprecision(2) << res << "\n";
    }
    return 0;
}
