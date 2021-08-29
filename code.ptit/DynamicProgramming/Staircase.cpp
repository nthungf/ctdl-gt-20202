/*
Một chiếc cầu thang có N bậc.
Mỗi bước, bạn được phép bước lên trên tối đa K bước.
Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang?
(Tổng số bước đúng bằng N).
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long

vector<ll> a;
int n, k;

void solve() {
    a.clear();
    a.resize(n + 5);
    a[0] = 1;
    a[1] = 1;
    a[2] = 2;
    for (ll i = 3; i <= n; i++) {
        for (ll j = i - 1; j >= i - k; j--) {
            if (j < 0)
                break;
            // if (j >= 0) {
            a[i] += a[j] % mod;
            a[i] %= mod;
            // }
        }
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        solve();
        // for (ll i = 1; i <= 10; i++) {
        //     cout << a[i] << " ";
        // }

        cout << a[n] << "\n";
    }
    return 0;
}