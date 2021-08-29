/*
Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử
theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở
vị trí số K sau khi trộn hai mảng để nhận được một mảng
được sắp xếp.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n, k;
        cin >> m >> n >> k;
        int p = m + n;
        vector<int> a(p);
        for (int i = 0; i < p; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << a[k - 1] << "\n";
    }
    return 0;
}