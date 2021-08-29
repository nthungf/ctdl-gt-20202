/*
Cho P1, P2 là hai biểu thức đúng chỉ bao gồm các ký tự
mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’ và các toán hạng in thường.
Nhiệm vụ của bạn là định xem P1 và P2 có giống nhau hay không.
*/

#include <bits/stdc++.h>
using namespace std;

string RemoveParentheses(string s) {
    string tmp = s;
    stack<int> a;
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp[i] == '(') {
            if (tmp[i - 1] == '-') a.push(1);
            else
                a.push('0');
        } else if (tmp[i] == ')') {
            tmp[i] = ' ';
            int x = i;
            int top;
            if (!a.empty()) {
                top = a.top();
                a.pop();
            } else
                top = 0;
            if (top == 1) {
                while (tmp[x] != '(') {
                    if (tmp[x] == '+') tmp[x] = '-';
                    else if (tmp[x] == '-')
                        tmp[x] = '+';
                    x--;
                }
            } else {
                while (tmp[x] != '(') {
                    x--;
                }
            }
            tmp[x] = ' ';
        }
    }
    tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
    return tmp;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string p1, p2;
        getline(cin, p1);
        getline(cin, p2);
        if (RemoveParentheses(p1) == RemoveParentheses(p2)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
