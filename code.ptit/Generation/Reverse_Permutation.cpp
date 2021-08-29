/*
 * Cho số nguyên dương N. Nhiệm vụ của bạn là
 * hãy liệt kê tất cả các hoán vị của 1, 2, .., N
 * theo thứ tự ngược. Ví dụ với N = 3 ta có
 * kết quả: 321, 312, 231, 213, 132, 123.
 */

#include <bits/stdc++.h>
using namespace std;

int ok = 1;
vector<int> a;

int n;

void output(vector<int> x) {
    for (int i = 1; i <= n; ++i) {
        cout << x[i];
    }
    cout << ' ';
}
void reverse(int l, int r) {
    while (l <= r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}

void nextPermutation() {
    int i = n - 1;
    while (a[i] > a[i + 1])
        i--;
    if (i > 0) {
        int k = n;
        while (a[k] < a[i])
            k--;
        swap(a[i], a[k]);
        reverse(i + 1, n);
    } else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = 1;
        vector<vector<int> > res;
        a.clear();
        a.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            a[i] = i;
        }
        while (ok) {
            // output();
            res.push_back(a);
            nextPermutation();
        }
        for (int i = res.size() - 1; i >= 0; --i) {
            output(res[i]);
        }
        cout << "\n";
    }
}