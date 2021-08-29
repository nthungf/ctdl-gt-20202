/*

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll res = 1;
        for (ll i = n - k + 1; i <= n; i++) {
            res = (res % mod * i % mod) % mod;
        }
        cout << res << "\n";
    }
    return 0;
}