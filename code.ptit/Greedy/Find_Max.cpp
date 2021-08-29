/*
Cho mảng A[] gồm N phần tử.Nhiệm vụ của bạn là
tìm max = /Sigma_(i=0)^(n-1) A_i * i bằng cách sắp đặt
lại các phần tử trong mảng. Chú ý, kết quả của bài toán
có thể rất lớn vì vậy bạn hãy đưa ra kết quả lấy
modulo với 10^9+7.
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

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
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i] * i;
            sum %= mod;
        }
        cout << sum << "\n";
    }
    return 0;
}