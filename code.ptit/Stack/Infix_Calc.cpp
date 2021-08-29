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
    stack<string> a;
    string res;
    for (int i = 0; i < s.size(); i++) {
        char x = s[i];
        if (x == '_') res += x;
        if (x == '(') a.push(string(1, x));
        else if (isDigit(s[i])) {
            res += '_';
            while (isDigit(s[i])) {
                res += s[i];
                i++;
            }
            res += '_';
            i--;
        } else if (isOp(x)) {
            string xxx = {'_', x, '_'};
            if (a.empty()) {
                a.push(xxx);
            } else {
                char y = a.top()[1];
                // a.pop();
                if (priority(x) >= priority(y)) {
                    a.push(xxx);
                } else {
                    // y = a.top();
                    a.pop();
                    res += y;
                    a.push(xxx);
                }
            }
        } else if (x == ')') {
            while (a.top() != "(") {
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

int DOO(ll a, ll b, char x) {
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
            ll num = 0;
            while (isDigit(pf[i])) {
                num = num * 10 + (pf[i] - '0');
                i++;
            }
            i--;
            // cout << num << "\n";
            a.push(num);
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
        string pf = InfixToPostfix(s);
        Calc(pf);
    }
    return 0;
}