/*
 * Cho số nguyên dương N và K. Hãy tính N^K modulo 10^9+7.
 */
#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

ll res;

ll power(ll x, ll y) {
    if (y == 0) res = 1;
    else if (y == 1)
        res = x;
    else {
        res = power(x, y / 2);
        res = (res * res) % mod;
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
    }
    return res % mod;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        res = 0;
        ll n, k;
        cin >> n >> k;
        cout << power(n, k) << '\n';
    }
    return 0;
}