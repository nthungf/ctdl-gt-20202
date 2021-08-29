/*
Một phân số đơn vị nếu tử số của phân số đó là 1.
Mọi phân số nguyên dương đều có thể biểu diễn thành
tổng các phân số đơn vị. Ví dụ 2/3 = 1/2  + 1/6.
Cho phân số nguyên dương P/Q bất kỳ (P < Q),
hãy biểu diễn phân số nguyên dương thành tổng phân số
đơn vị với số hạng tử là ít nhất.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long

void solve(ll p, ll q) {
    if (p == 0 || q == 0)
        return;
    if (q % p == 0) {
        cout << "1/" << q / p;
        return;
    }
    if (p % q == 0) {
        cout << p / q;
        return;
    }
    if (p > q) {
        cout << p / q << " + ";
        solve(p % q, q);
        return;
    }

    ll n = q / p + 1;
    cout << "1/" << n << " + ";

    solve(n * p - q, n * q);
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll p, q;
        cin >> p >> q;
        solve(p, q);
        cout << "\n";
    }
    return 0;
}