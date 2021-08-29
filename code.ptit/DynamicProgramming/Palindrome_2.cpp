/*
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm số phép 
loại bỏ ít nhất các ký tự trong S để S trở thành 
xâu đối xứng. Chú ý, phép loại bỏ phải bảo toàn 
tính trước sau của các ký tự trong S.
*/

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
        for (int d = 1; d < n; ++d) {
            for (int i = 0; i < n - d; ++i) {
                int j = i + d;
                // cout<<i<<" "<<j<<"\n";
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        cout << n - dp[0][n - 1] << "\n";
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
    }
    return 0;
}