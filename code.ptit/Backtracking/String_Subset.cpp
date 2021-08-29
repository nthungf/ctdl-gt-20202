/*
Cho một xâu ký tự S không có ký tự lặp lại.
Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<string> res;
        // k ki tu
        for (int k = 1; k <= n; k++) {
            // bat dau tu i
            for (int i = 0; i + k <= n; i++) {
                string tmp = "";
                for (int j = i; j < i + k; j++) {
                    tmp += s[j];
                }
                // cout << tmp << '\n';
                res.push_back(tmp);
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}