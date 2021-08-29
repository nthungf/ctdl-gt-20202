#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, n;
    cin >> c >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<vector<bool> > dp(n + 1, vector<int>(c + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= c; ++j) {
            if (j == 0)
                dp[i][j] = true;
            else if (a[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i]]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for(int j=0;j<=c;j++){
        	cout<<c[j]<<"\n";
        }
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    return 0;
}