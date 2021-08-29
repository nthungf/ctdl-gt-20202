/*
Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}.
Tìm ra một dãy con của dãy A
(không nhất thiết là các phần tử liên tiếp trong dãy)
có tổng bằng S cho trước.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        vector<vector<int> > dp(n + 1, vector<int>(s + 1));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= s; ++j) {
                if (a[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i]]);
                }
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for(int j=0; j<=s;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<dp[n][s] << "\n";
        dp[n][s] ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}