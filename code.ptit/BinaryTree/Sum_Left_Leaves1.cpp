/*

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct edge {
    ll u, v;
    char x;
};

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        ll sum = 0;
        cin >> n;
        vector<edge> a(n);
        set<ll> m;
        for (ll i = 0; i < n; i++) {
            cin >> a[i].u >> a[i].v >> a[i].x;
            m.insert(a[i].u);
        }
        for (ll i = 0; i < n; i++) {
            // neu a[i].v khong la node cha
            if (m.find(a[i].v) == m.end() && a[i].x == 'L') {
                // cout << a[i].v << "\n";
                sum += a[i].v;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}