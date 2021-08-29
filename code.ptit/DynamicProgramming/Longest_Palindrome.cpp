// Xau con lien tiep

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        int res = 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                res = 2;
            }
        }
        for (int d = 2; d < n; ++d) {
            for (int i = 0; i < n - d; ++i) {
                int j = i + d;
                // cout << i << " " << j << "\n";
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    if (d + 1 > res)
                        res = d + 1;
                    // cout << "--" << res << "\n";
                }
            }
        }
        cout << res << "\n";
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }
    return 0;
}