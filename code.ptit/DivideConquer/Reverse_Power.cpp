/*
Cho mảng số N. Ta gọi số đảo của N là R.
Hãy tìm lũy thừa R của N.
Đưa ra kết quả của bài toán dưới dạng modulo với 10^9 + 7.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

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
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        res = 0;
        ll n, r = 0;
        cin >> n;
        for (ll i = n; i > 0; i /= 10) {
            r = (r * 10) + (i % 10);
        }
        cout << power(n, r) % mod << '\n';
    }
    return 0;
}