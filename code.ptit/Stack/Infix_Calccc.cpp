/*
Cho biểu thức trung tố S với các toán tử +, -, *, / và dấu ngoặc ().
Các toán hạng là các số có giá trị không vượt quá 100.
Hãy tính giá trị biểu thức S.
Phép chia thực hiện với số nguyên, input đảm bảo
số bị chia luôn khác 0, đáp số biểu thức có không quá 10 chữ số.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int priority(char x) {
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

bool isOp(char x) { return (x == '+' || x == '-' || x == '*' || x == '/'); }

bool isDigit(char x) { return ('0' <= x && x <= '9'); }

string InfixToPostfix(string s) {
    stack<char> a;
    string res;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == ' ') res += x;
        if (x == '(') a.push(x);
        else if ('0' <= x && x <= '9') {
            res += x;
        } else if (isOp(x)) {
            if (a.empty()) {
                a.push(x);
            } else {
                char y = a.top();
                // a.pop();
                if (priority(x) >= priority(y)) {
                    a.push(x);
                } else {
                    // y = a.top();
                    a.pop();
                    res += y;
                    a.push(x);
                }
            }
        } else if (x == ')') {
            while (a.top() != '(') {
                res += a.top();
                a.pop();
            }
            a.pop();
        }
    }
    while (!a.empty()) {
        res += a.top();
        a.pop();
    }
    // cout << res << "\n";
    return res;
}

int DOO(int a, int b, char x) {
    switch (x) {
    case '+': return a + b; break;
    case '-': return a - b; break;
    case '*': return a * b; break;
    case '/': return a / b; break;
    default: return 0; break;
    }
}

void Calc(string pf) {
    stack<ll> a;
    cout << pf << "\n";
    for (int i = 0; i < pf.size(); i++) {
        if (isDigit(pf[i])) {
            if (!a.empty()) {
                ll num = a.top();
                a.pop();
                num = num * 10 + (pf[i] - '0');
                // cout << num << "\n";
                a.push(num);
            } else
                a.push(pf[i] - '0');
        } else if (isOp(pf[i])) {
            ll op2 = a.top();
            a.pop();
            ll op1 = a.top();
            a.pop();
            // cout << op1 << " " << pf[i] << " " << op2 << "\n";
            ll kq = DOO(op1, op2, pf[i]);
            // cout << "kq " << kq << "\n";
            a.push(kq);
        }
    }
    cout << a.top() << "\n";
    return;
}

int main() {
    int t;
    cin >> t;
    // cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (isOp(s[i])) {
                s.insert(i, " ");
                s.insert(i + 2, " ");
                i += 2;
            }
        }
        // cout << s << "\n";
        string pf = InfixToPostfix(s);
        Calc(pf);
    }
    return 0;
}