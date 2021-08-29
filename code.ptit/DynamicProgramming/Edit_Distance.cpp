/*
Cho hai xâu ký tự str1, str2 bao gồm các ký tự
in thường và các thao tác dưới đây:

Insert: chèn một ký tự bất kỳ vào str1.
Delete: loại bỏ một ký tự bất kỳ trong str1.
Replace: thay một ký tự bất kỳ trong str1.

Nhiệm vụ của bạn là đếm số các phép Insert, Delete,
Replace ít nhất thực hiện trên str1 để trở thành str2.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.size(), n2 = s2.size();
        s1.insert(0, " ");
        s2.insert(0, " ");
        // cout << s1 << "\n" << s2 << "\n";
        int dp[n2 + 5][n1 + 5];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n2; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= n1; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n2; ++i) {
            for (int j = 1; j <= n1; ++j) {
                if (s1[j] == s2[i]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int x =
                        min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                    dp[i][j] = 1 + x;
                }
            }
        }
        // for (int i = 0; i <= n2; ++i) {
        //     for (int j = 0; j <= n1; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << dp[n2][n1] << "\n";
    }
    return 0;
}