/*
Cho mảng A[] gồm n phần tử, hãy đưa ra số nhỏ nhất
và số nhỏ thứ hai của mảng. Nếu không có số nhỏ thứ hai,
hãy đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        if (a.size() < 2) {
            cout << "-1\n";
        } else {
            cout << a[0] << " " << a[1] << "\n";
        }
    }
    return 0;
}