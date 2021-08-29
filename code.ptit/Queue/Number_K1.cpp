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
        int x = i;
        priority_queue<int> q;
        for (int x = i; x > 0; x /= 10) {
            int digit = x % 10;
            q.push(digit);
        }
        vs[i] = 1;
        if (q.top() > 5) {
            vs[i] = 0;
        }
        int x1, x2;
        while (!q.empty()) {
            x1 = q.top();
            q.pop();
            x2 = -1;
            if (!q.empty()) {
                x2 = q.top();
            }
            if (x1 == x2) {
                vs[i] = 0;
                break;
            }
        }
    }
    // cout << dem << "\n";
}

void Solve() {
    int dem = 0;
    for (int i = l; i <= r; ++i) {
        if (vs[i]) {
            ++dem;
            // cout << i << "\n";
        }
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
