/*
Cho biểu thức số học, hãy cho biết biểu thức số học
có dư thừa các cặp ký hiệu ‘(’,’) ‘ hay không?
*/

#include <bits/stdc++.h>
using namespace std;

int isOperator(char x) { return (x == '+' || x == '-' || x == '*' || x == '/'); }

int check(string s) {
    stack<string> a;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || isOperator(s[i])) a.push(string(1, s[i]));
        else if (s[i] == ')') {
            if (a.top() == "(") return 1;
            else {
                while (a.top() != "(") a.pop();
                if (a.top() == "(") a.pop();
            }
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        check(s) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}