// Xau con lien tiep

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1;
        s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.size();
        int l[n + 5][n + 5];
        memset(l, 0, sizeof(l));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) l[i][j] = 1 + l[i - 1][j - 1];
                else
                    l[i][j] = max(l[i - 1][j], l[i][j - 1]);
            }
        }
        cout << l[n][n] << "\n";
    }
    return 0;
}
