/*
 * Cho hai số nguyên dương S và D,
 * trong đó S là tổng các chữ số và D
 * là số các chữ số của một số.
 * Nhiệm vụ của bạn là tìm số nhỏ nhất
 * thỏa mãn S và D? Ví dụ với S = 9, D = 2
 * ta có số nhỏ nhất thỏa mãn S và D là 18.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        if (s == 0 && d == 1) {
            cout << "0\n";
            continue;
        }
        if (9 * d < s || s == 0) {
            cout << "-1\n";
            continue;
        }
        vector<int> a;
        for (int i = 0; i < d; ++i) {
            if (s >= 10) {
                a.push_back(9);
                s -= 9;
            } else {
                a.push_back(s);
                s -= s;
            }
        }
        sort(a.begin(), a.end());
        if (a[0] == 0) {
            a[0] += 1;
            for (int i = 1; i < a.size(); ++i) {
                if (a[i] > 0) {
                    a[i] -= 1;
                    break;
                }
            }
        }
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i];
        }
        cout << "\n";
    }
}