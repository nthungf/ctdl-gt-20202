#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        stack<int> a;
        a.push(-1);
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') a.push(i);
            else if (s[i] == ')') {
                if (!a.empty()) a.pop();
                if (!a.empty()) {
                    int tmp = i - a.top();
                    if (tmp > res) res = tmp;
                } else
                    a.push(i);
            }
        }
        cout << res << "\n";
    }
    return 0;
}