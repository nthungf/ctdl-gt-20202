/*
Cho số nguyên dương N được biểu diễn như một xâu ký tự số.
Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi
các xâu con của N.
Ví dụ N=”1234” ta có kết quả là
1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll to(char x) { return x - '0'; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        // cout << n.size() << "\n";
        vector<ll> dp(n.size() + 1);
        dp[0] = to(n[0]);
        // cout << dp[0] << " ";
        ll sum = dp[0];
        for (int i = 1; i < n.size(); i++) {
            dp[i] = (dp[i - 1] * 10) + (i + 1) * to(n[i]);
            sum += dp[i];
            // cout << dp[i] << " ";
        }
        // cout << dp[n.size()-1] << "\n";
        cout << sum << '\n';
    }
    return 0;
}