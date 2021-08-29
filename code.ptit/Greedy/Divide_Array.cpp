/*
Cho mảng A[] gồm N số nguyên không âm và số K.
Nhiệm vụ của bạn là hãy chia mảng A[] thành hai mảng con
có kích cỡ K và N-K sao cho hiệu giữa tổng hai mảng con là
lớn nhất. Ví dụ với mảng A[] = {8, 4, 5, 2, 10}, K=2 ta có
kết quả là 17 vì mảng A[] được chia thành hai mảng
{4, 2} và { 8, 5,10} có hiệu của hai mảng con là 23-6=17
là lớn nhất.
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
        sort(a.begin(), a.end());
        if (k > n - k) {
            k = n - k;
        }

        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++) {
            sum1 += a[i];
        }
        for (int i = k; i < n; i++) {
            sum2 += a[i];
        }
        // cout << sum1 << " " << sum2 << "\n";
        cout << sum2 - sum1 << "\n";
    }
    return 0;
}