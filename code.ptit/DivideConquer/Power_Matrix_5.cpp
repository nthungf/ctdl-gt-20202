/*
Cho ma trận vuông A kích thước N x N.
Nhiệm vụ của bạn là hãy tính ma trận X = AK
với K là số nguyên cho trước.
Sau đó, tính tổng các phần tử của hàng cuối cùng.
Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define max 11

int n;
ll k;
vector<vector<ll> > a, b;

void Multiply(vector<vector<ll> > x, vector<vector<ll> > y) {
    // a[i][j] = \Sum{ x[i][k] + y[k][j] }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                a[i][j] += (x[i][k] % mod * y[k][j] % mod) % mod;
                a[i][j] %= mod;
            }
        }
    }
}

void Power(ll k) {
    if (k <= 1) {
        return;
    } else {
        Power(k / 2);
        Multiply(a, a);
        if (k % 2 == 1) Multiply(a, b);
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.clear();
        a.resize(n, vector<ll>(n));
        b.clear();
        b.resize(n, vector<ll>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> a[i][j];
                b[i][j] = a[i][j];
            }
        }
        Power(k);
        ll res = 0;
        for (int i = 0; i < n; ++i) {
            res += a[n - 1][i];
            res %= mod;
        }
        cout << res << "\n";
    }
    return 0;
}
