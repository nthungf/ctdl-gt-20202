/*
Cho mảng A[] gồm các số từ 0 đến 9.
Nhiệm vụ của bạn là tìm tổng nhỏ nhất của hai số
được tạo bởi các số trong mảng A[].
Chú ý, tất cả các số trong mảng A[] đều được sử dụng
để tạo nên hai số.
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
        string s1, s2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                s1.push_back(a[i] + '0');
            else
                s2.push_back(a[i] + '0');
        }
        long long n1 = 0, n2 = 0;
        for (int i = 0; i < s1.size(); i++) {
            n1 = n1 * 10 + (s1[i] - '0');
        }
        for (int i = 0; i < s2.size(); i++) {
            n2 = n2 * 10 + (s2[i] - '0');
        }
        cout << n1 + n2 << "\n";
        // cout << s1 << " " << s2 << " " << n1 << " " << n2 << "\n";
    }
    return 0;
}