#include <bits/stdc++.h>
using namespace std;

int isOperator(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res;
        stack<string> a;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (!isOperator(s[i])) {
                a.push(string(1, s[i]));
            } else {
                string x1 = a.top();
                a.pop();
                string x2 = a.top();
                a.pop();
                // cout << x1 << " " << x2 << " " << s[i] << "\n";
                string tmp = s[i] + x2 + x1;
                a.push(tmp);
            }
        }
        cout << a.top() << "\n";
    }
    return 0;
}