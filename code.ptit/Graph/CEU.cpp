/*

*/

#include <bits/stdc++.h>
using namespace std;

int a[100][100], n, m, u, ce[100];

void Euler() {
    int v, k = 0;
    stack<int> s;
    s.push(u);
    while (s.empty() == 0) {
        v = s.top();
        // cout << v << "\n";
        int ok = 1;
        for (int x = 1; x <= n; ++x) {
            if (a[v][x] == 1) {
            	// cout << v << " " << x << "\n";
                s.push(x);
                ok = 0;
                a[v][x] = 0;
                a[x][v] = 0;
                break;
            }
        }
        if (ok == 1) {
            k++;
            ce[k] = v;
            s.pop();
            // cout << "pop\n";
        }
    }
    for (v = k; v > 0; v--) cout << ce[v] << " ";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        u = 3;
        memset(a, 0, sizeof(a));
        memset(ce, 0, sizeof(ce));
        for (int i = 0; i < m; ++i) {
            int v1, v2;
            cin >> v1 >> v2;
            a[v1][v2] = 1;
            a[v2][v1] = 1;
        }
        Euler();
        cout << "\n";
    }
    return 0;
}
