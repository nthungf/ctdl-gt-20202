/*
Một người có cái túi thể tích V (V<1000).
Anh ta có N đồ vật cần mang theo (N≤1000),
mỗi đồ vật có thể tích là A[i] (A[i]≤100) và
giá trị là C[i] (C[i]≤100).
Hãy xác định tổng giá trị lớn nhất của các đồ vật
mà người đó có thể mang theo, sao cho tổng thể tích
không vượt quá V.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, v;
        cin >> n >> v;
        vector<int> a(n + 5);
        vector<int> c(n + 5);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> c[i];
        vector<vector<int> > dp(n + 5, vector<int>(v + 5));
        // dp[i][j] : chon do vat thu i voi the tich lon nhat la j
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= v; j++) {
                int ko_chon = dp[i - 1][j];
                int chon = -1;
                if (a[i] <= j) chon = dp[i - 1][j - a[i]] + c[i];
                dp[i][j] = max(ko_chon, chon);
            }
        }
        // cout << "\n\n";
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= v; j++) {
        //         cout << setw(2) << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        cout << dp[n][v] << "\n";
    }
    return 0;
}