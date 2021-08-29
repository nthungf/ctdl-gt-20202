/*
Cho mảng A[] gồm n số nguyên khác nhau.
Hãy đưa ra các phần tử của mảng theo khuôn dạng
lớn nhất, nhỏ nhất, lớn thứ hai, nhỏ thứ 2, …
Ví dụ với A[] = {9, 7, 12, 8, 6, 5}
ta đưa ra : 12, 5, 9, 6, 8, 7.
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
        vector<int> b;
        int l = 0, r = n - 1;
        while (l <= r && b.size() < n) {
            b.push_back(a[r]);
            b.push_back(a[l]);
            r--;
            l++;
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}