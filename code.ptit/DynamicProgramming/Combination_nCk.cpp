/*
(n)C(k) = (n-1)C(k) + (n-1)C(k-1)
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int C[1002][1002];

void preCalc() {
    for (ll i = 0; i <= 1000; i++) {
        C[0][i] = 1;
    }
    for (ll i = 0; i <= 1000; i++) {
        C[1][i] = i;
    }
    for (ll i = 1; i <= 1000; i++) {
        for (ll j = 1; j <= 1000; j++) {
            C[i][j] = (C[i][j - 1] % mod + C[i - 1][j - 1] % mod) % mod;
        }
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        ll n, k;
        cin >> n >> k;
        cout << C[k][n] << "\n";
    }
    return 0;
}