/*
Cho mảng đã được sắp xếp A[] gồm N phần tử
không có hai phần tử giống nhau và số X.
Nhiệm vụ của bạn là tìm floor(X). Trong đó,
K=floor(X) là phần tử lớn nhất trong mảng A[]
nhỏ hơn hoặc bằng X.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> a, int xx) {
    int l = 0, r = a.size() - 1;
    int mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == xx)
            return mid;
        else if (xx < a[mid]) {
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return -1;
}

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
        cout << *lower_bound(a.begin(), a.end(), x) << "\n";
    }
    return 0;
}