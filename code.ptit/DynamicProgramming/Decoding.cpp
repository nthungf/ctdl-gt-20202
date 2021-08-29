/*
Một bản tin M đã mã hóa bí mật thành các con số theo
ánh xạ như sau: ‘A’->1, ‘B’->2, .., ‘Z’->26.
Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M.
Ví dụ với bản mã M=”123” nó có thể được
giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string m;
        cin >> m;
        if (m[0] == '0') {
            cout << "0\n";
            continue;
        }
        int n = m.size();
        int dp[n + 1] = {0};
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // dp[i] = 0;
            if (m[i - 1] > '0')
                dp[i] = dp[i - 1];
            if (m[i - 2] == '1' || (m[i - 2] == '2' && m[i - 1] <= '6'))
                dp[i] += dp[i - 2];
        }
        // for (int i = 0; i < n; ++i) {
        //     cout << dp[i] << " ";
        // }
        cout<<dp[n]<<"\n";
    }
    return 0;
}