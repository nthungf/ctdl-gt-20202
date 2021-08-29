/*
Một xâu nhị phân độ dài n được gọi là thuận nghịch
hay đối xứng nếu đảo ngược xâu nhị phân đó ta vẫn
nhận được chính nó. Cho số tự nhiên n (n nhập từ bàn phím).
Hãy viết chương trình liệt kê tất cả các xâu nhị phân
thuận nghịch có độ dài n.
*/

#include <bits/stdc++.h>
using namespace std;

int n, ok;
vector<int> a;

void Init() {
    ok = 1;
    cin >> n;
    a.clear();
    a.resize(n);
}

void Gen() {
    int i = n - 1;
    while (a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if (i >= 0) {
        a[i] = 1;
    } else
        ok = 0;
}

void Result() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int check() {
    vector<int> b = a;
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (b[i] != a[i])
            return 0;
    }
    return 1;
}

int main() {
    // int t;
    // cin >> t;
    // while (t--) {
    Init();
    while (ok) {
        if (check())
            Result();
        Gen();
    }
    // }
    return 0;
}