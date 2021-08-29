/*
Cho số nguyên dương n.
Hãy cho biết có bao nhiêu dãy số nguyên dương
có tổng các phần tử trong dãy bằng n.
*/
// 2^(n-1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 123456789

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
        ll n;
        cin >> n;
        cout << power(2, n - 1) << "\n";
    }
    return 0;
}
