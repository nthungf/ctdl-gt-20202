/*
Cho xâu ký tự S. Nhiệm vụ của bạn là tìm độ dài
dãy con lặp lại dài nhất trong S.
Dãy con có thể chứa các phần tử không liên tiếp nhau.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1;
        s2 = s1;
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
        cout << l[n][m] << "\n";
    }
    return 0;
}