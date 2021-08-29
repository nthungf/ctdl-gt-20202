/*
Cho dãy số a[] có n phần tử, đánh số từ 1 đến n.
Hãy sắp xếp các phần tử ở vị trí lẻ theo thứ tự tăng dần,
các phần tử ở vị trí chẵn theo thứ tự giảm dần.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 1) {
            a.push_back(x);
        } else
            b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int n1 = min(a.size(), b.size());
    int n2 = max(a.size(), b.size());
    // cout << n1 << " " << n2 << "\n";
    int i = 0;
    for (i = 0; i < n1; ++i) {
        cout << a[i] << " " << b[i] << " ";
    }
    // cout << i << "\n";
    if (n2 > n1) {
        if (n2 == a.size()) {
            cout << a[i] << " ";
        } else if (n2 == b.size()) {
            cout << b[i] << " ";
        }
    }
    cout << "\n";
    return 0;
}
