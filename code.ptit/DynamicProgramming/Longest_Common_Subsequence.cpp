/*
Cho 2 xâu S1 và S2.
Hãy tìm xâu con chung dài nhất của 2 xâu này
(các phần tử không nhất thiết phải liên tiếp nhau).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        int m = s2.size();
        vector<vector<int> > l(n + 5, vector<int>(m + 5));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    // cout << s1[i - 1] << " " << s2[j - 1] << "\n";
                    l[i][j] = 1 + l[i - 1][j - 1];
                } else
                    l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout << l[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        cout << l[n][m] << "\n";
    }
    return 0;
}