/*
Một dãy số tự nhiên bắt đầu bởi con số 1 và được
thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:

Với dãy số A hiện tại, dãy số mới có dạng A, x, A
trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] à [1 2 1] à
[1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng
là bao nhiêu?
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll tmp = n;
        ll size = 1;
        for (ll i = 0; i < n - 1; i++) {
            size = size * 2 + 1;
        }
        // cout << size << "\n";
        // cout << size / 2 << "\n";
        while (size >= 1 && tmp >= 1) {
            // cout << tmp << " " << size << " " << k << "\n";
            if (k == (size / 2 + 1)) {
                k = tmp;
                cout << k << '\n';
                break;
            } else if (k < (size / 2 + 1)) {
                size = size / 2;
            } else {
                size = size / 2;
                k = k - (size + 1);
            }
            tmp--;
        }
        // cout << k << '\n';
    }
    return 0;
}