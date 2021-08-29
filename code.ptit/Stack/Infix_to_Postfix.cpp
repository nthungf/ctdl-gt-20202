#include <bits/stdc++.h>
using namespace std;

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    if (x == '(' || x == ')') return 0;
    return -1;
}

int isOperand(char x) { return (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')); }

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> a;
        string res;
        // cout<<s<<"\n";
        for (int i = 0; i < s.size(); ++i) {

            if (isOperand(s[i])) res += s[i]; // toan hang

            else if (s[i] == '(') // (
                a.push('(');

            else if (s[i] == ')') { // )
                while (a.top() != '(' && !a.empty()) {
                    char tmp = a.top();
                    a.pop();
                    res += tmp;
                }
                if (a.top() == '(') a.pop();
            }

            else { // phep toan
                while (!a.empty() && priority(s[i]) <= priority(a.top())) {
                    char tmp = a.top();
                    a.pop();
                    res += tmp;
                }
                a.push(s[i]);
            }
        }
        while (!a.empty()) {
            char tmp = a.top();
            if (tmp != '(') res = res + tmp;
            a.pop();
        }
        cout << res << "\n";
    }
    return 0;
}