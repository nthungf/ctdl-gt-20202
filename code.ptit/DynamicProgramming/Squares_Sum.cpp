/*
Mọi số nguyên dương N đều có thể phân tích thành
tổng các bình phương của các số nhỏ hơn N.
Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52.
Cho số nguyên dương N. Nhiệm vụ của bạn là tìm
số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.
*/

#include <bits/stdc++.h>
using namespace std;
#define max 10010

int dp[max];

void preCalc() {
    for (int n = 0; n < max; ++n) {
        dp[n] = n;
        for (int i = 1; i <= sqrt(n); ++i) {
            dp[n] = min(dp[n], 1 + dp[n - i * i]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        int n; cin >> n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}
