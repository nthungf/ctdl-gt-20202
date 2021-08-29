/*
Cho biểu thức đúng P chỉ bao gồm các phép toán +, -,
các toán hạng cùng với các ký tự ‘(’, ‘)’.
Hãy bỏ tất cả các ký tự ‘(’, ‘)’ trong P để nhận được
biểu thức tương đương.
Ví dụ với P = a – (b + c) ta có kết quả P = a – b – c .
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> a;
        string res;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(')
                if (s[i - 1] == '-') a.push(1);
                else
                    a.push(0);
            else if (s[i] == ')') {
                s[i] = ' ';
                int x = i;
                int top;
                if (!a.empty()) {
                    top = a.top();
                    a.pop();
                } else
                    top = 0;
                // cout << top << "\n";
                if (top == 1) {
                    while (s[x] != '(') {
                        if (s[x] == '+') s[x] = '-';
                        else if (s[x] == '-')
                            s[x] = '+';
                        // cout << s[x] << "\n";
                        x--;
                    }
                } else {
                    while (s[x] != '(') {
                        x--;
                    }
                }
                s[x] = ' ';
            }
        }
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        cout << s << "\n";
    }
    return 0;
}