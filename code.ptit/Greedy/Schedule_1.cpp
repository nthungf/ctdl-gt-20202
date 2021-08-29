/*

*/

#include <bits/stdc++.h>
using namespace std;

struct boo {
    int s, f;
};

int cmp(boo x, boo y) { return x.f < y.f; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<boo> w(n + 5);
        for (int i = 0; i < n; i++) {
            cin >> w[i].s;
        }
        for (int i = 0; i < n; i++) {
            cin >> w[i].f;
        }
        sort(w.begin(), w.begin() + n, cmp);
        int dem = 1;

        int i = 1, j = 0;
        while (i < n) {
            if (w[i].s >= w[j].f) {
                ++dem;
                j = i;
            }
            i++;
        }
        cout << dem << "\n";

        // for (int i = 0; i < n; i++) {
        //     cout << w[i].s << " " << w[i].f << "\n";
        // }
    }
    return 0;
}