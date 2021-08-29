/*
Cho dãy số A[] gồm N phần tử.
Hãy tìm tổng lớn nhất của dãy con của dãy số A[]
sao cho dãy con không có hai số cạnh nhau trong A[].
Ví dụ với A[] = {6, 7, 1, 3, 8, 2, 4} ta có kết quả là
19 tương ứng với tổng của dãy con {6, 1, 6, 4} không
có hai phần tử nào kề nhau trong A[].
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), sum(n);
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll incl = a[0], excl = 0;
        for (ll i = 1; i < n; i++) {
            ll tmp = max(incl, excl);
            incl = excl + a[i];
            excl = tmp;
        }
        cout << max(incl, excl) << "\n";
    }
    return 0;
}