/*
Cho mảng A[] gồm n phần tử, hãy tìm k phần tử lớn nhất của mảng.
Các phần tử được đưa ra theo thứ tự giảm dần.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}