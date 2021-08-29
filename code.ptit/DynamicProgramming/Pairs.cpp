/*
Cho N cặp số, trong đó số thứ nhất bao giờ cũng
nhỏ hơn số thứ 2. Ta nói, cặp số <c, d> được gọi là
theo sau cặp số <a,b> nếu b<c.
Nhiệm vụ của bạn là tìm số lớn nhất chuỗi các cặp thỏa mãn
ràng buộc trên.
Ví dụ với các cặp
{<5, 24>, <39, 60>, <15, 28>, <27, 40>, <50, 90>}
 ta có kết quả là 3 tương ứng với chuỗi các cặp
{<5,24>, <27, 40>, <50, 90>}.
*/

#include <bits/stdc++.h>
using namespace std;

struct P {
    int x, y;
};

int cmp(P a, P b) { return a.y < b.y; }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<P> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y;
        }
        sort(a.begin(), a.end(), cmp);

        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int m = 0;
            for (int j = 0; j < i; j++) {
                if (dp[j] > m && a[j].y < a[i].x) {
                    m = dp[j];
                }
            }
            dp[i] = m + 1;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << a[i].x << " " << a[i].y << " " << dp[i] << "\n";
        // }
        cout << *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}