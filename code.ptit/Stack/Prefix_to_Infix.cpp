/*
Problem
*/

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
        stack<string> a;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (!isOperator(s[i])) {
                a.push(string(1, s[i]));
            } else {
                string x = a.top();
                a.pop();
                string y = a.top();
                a.pop();
                string tmp = ")" + y + s[i] + x + "(";
                // cout<<tmp<<"\n";
                a.push(tmp);
            }
        }
        string res = a.top();
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
    return 0;
}
