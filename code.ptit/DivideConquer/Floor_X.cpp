/*
Cho mảng đã được sắp xếp A[] gồm N phần tử
không có hai phần tử giống nhau và số X.
Nhiệm vụ của bạn là tìm floor(X). Trong đó,
K=floor(X) là phần tử lớn nhất trong mảng A[]
nhỏ hơn hoặc bằng X.
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
        int index = -1;
        int check = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                index = i;
                check = 1;
                break;
            } else if (a[i] > x) {
                index = i;
                check = 2;
                break;
            }
        }
        if (index > 0) {
            if (check == 1)
                cout << index + 1 << "\n";
            else if (check == 2)
                cout << index << "\n";
        } else
            cout << "-1\n";
    }
    return 0;
}