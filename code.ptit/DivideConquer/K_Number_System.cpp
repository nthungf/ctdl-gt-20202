/*
Cho hai số A, B ở hệ cơ số K. Hãy tính tổng hai số đó ở hệ cơ số K.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        string a, b;
        cin >> a >> b;
        long long na = 0, nb = 0;
        for (int i = 0; i < a.size(); i++) {
            na = na * k + (a[i] - '0');
        }
        for (int i = 0; i < b.size(); i++) {
            nb = nb * k + (b[i] - '0');
        }
        long long nn = na + nb;
        // cout << nn << "\n";
        vector<int> res;
        while (nn > 0) {
            long long du = nn % k;
            res.push_back(du);
            nn /= k;
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}