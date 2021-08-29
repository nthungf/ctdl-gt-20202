/*
Cho hai số nguyên dương L, R.
Hãy đưa ra số các số K trong khoảng [L, R] thỏa mãn điều kiện:
        Tất cả các chữ số của K đều khác nhau.
        Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5.
*/

#include <bits/stdc++.h>
using namespace std;

int l, r;

int vs[100001];

void preCalc() {
    // int dem = 0;
    for (int i = 1; i <= 100000; ++i) {
        string s = to_string(i);
        // cout << s << " ";
        string x = s;
        sort(x.begin(), x.end(), greater<char>());
        x.erase(unique(x.begin(), x.end()), x.end());
        // cout << x << " ";
        if (x.size() == s.size() && x[0] <= '5') {
            // cout << s << " ";
            vs[i] = 1;
            // ++dem;
        }
    }
    // cout << dem << "\n";
}

void Solve() {
    int dem = 0;
    for (int i = l; i <= r; ++i) {
        if (vs[i]) ++dem;
    }
    cout << dem << "\n";
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        cin >> l >> r;
        Solve();
    }
    return 0;
}
