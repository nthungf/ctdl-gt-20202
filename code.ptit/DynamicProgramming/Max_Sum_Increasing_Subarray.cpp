/*
Cho dãy số A[] gồm N số. Nhiệm vụ của bạn là
tìm tổng lớn nhất của dãy con được sắp theo thứ tự
tăng dần của dãy A[].
Ví dụ với dãy A[] = {1, 101, 2, 3, 100, 4, 5} ta có
kết quả là 106 = 1 + 2 + 3 + 100.
Với dãy A[] = {10, 7, 5} ta có kết quả là 10.
Với dãy A[] = {1, 2, 3, 5} ta có kết quả là 11.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), sum(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sum[0] = a[0];
        for (int i = 1; i < n; i++) {
            int maxs = 0;
            for (int j = 0; j < i; j++) {
                if (sum[j] > maxs && a[j] < a[i]) {
                    maxs = sum[j];
                }
            }
            sum[i] = maxs + a[i];
        }
        // for (int i = 0; i < n; i++) {
        //     cout << sum[i] << " ";
        // }
        // cout << "\n";
        cout << *max_element(sum.begin(), sum.end()) << "\n";
    }
    return 0;
}