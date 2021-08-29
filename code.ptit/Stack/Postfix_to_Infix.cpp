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
        for (int i = 0; i < s.size(); ++i) {
            if (!isOperator(s[i])) {
                string tmp = string(1, s[i]);
                a.push(tmp);
            } else {
                string x = a.top();
                a.pop();
                string y = a.top();
                a.pop();
                string tmp = "(" + y + s[i] + x + ")";
                // cout<<tmp<<"\n";
                a.push(tmp);
            }
        }
        cout << a.top() << "\n";
    }
    return 0;
}