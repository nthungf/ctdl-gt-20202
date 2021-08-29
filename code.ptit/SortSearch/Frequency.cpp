/*
Cho mảng A[] gồm n phần tử đã được sắp xếp.
Hãy tìm số lần xuất hiện số X trong mảng.
Nếu số lần xuất hiện số x trong mảng là 0 hãy đưa ra -1.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (!binary_search(a.begin(), a.end(), x)) {
            cout << "-1\n";
            continue;
        }
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x)
                ++dem;
        }
        cout << dem << "\n";
    }
    return 0;
}