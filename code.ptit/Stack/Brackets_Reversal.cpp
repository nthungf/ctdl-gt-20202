/*
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn.
Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất,
sao cho xâu mới thu được là một dãy ngoặc đúng.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> a;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') a.push(s[i]);
            else if (s[i] == ')') {
                if (!a.empty() && a.top() == '(') {
                    a.pop();
                } else
                    a.push(s[i]);
            }
        }
        string res;
        while (!a.empty()) {
            res = a.top() + res;
            // cout << a.top();
            a.pop();
        }
        // cout << res << "\n";
        int n = 0, m = 0;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] == ')') m++;
            else
                n++;
        }
        if (m % 2 == 0) m /= 2;
        else
            m = m / 2 + 1;
        if (n % 2 == 0) n /= 2;
        else
            n = n / 2 + 1;

        cout << m + n << "\n";
    }
    return 0;
}
