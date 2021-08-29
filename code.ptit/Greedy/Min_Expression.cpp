/*
Cho mảng A[], B[] đều có N phần tử.
Nhiệm vụ của bạn là tìm giá trị nhỏ nhất của
biểu thức P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1]
bằng cách tráo đổi vị trí các phần tử của cả mảng A[] và B[].
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (a[i] * b[i]);
        }
        cout << sum << "\n";
    }
    return 0;
}