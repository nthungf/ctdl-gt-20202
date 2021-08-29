/*
Xét các số X có các chữ số được sắp xếp tăng dần,
tức a[1] ≤ a[2] ≤ … ≤ a[N] trong đó a[1], a[2], …, a[N]
lần lượt là các chữ số của X. Chẳng hạn 223, 8999, …

Cho trước số chữ số N. Nhiệm vụ của bạn là đếm xem có
bao nhiêu số như vậy.
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int dp[20][110];

void preCalc() {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 9; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[0][j] = 1;
            if (j == 1) dp[i][j] = i + 1;
            else {
                dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        int n;
        cin >> n;
        // dp[i][j]: so co do dai j ket thuc boi chu so i
        // 10 hang, n cot
        cout << dp[9][n] << "\n";
    }
    return 0;
}