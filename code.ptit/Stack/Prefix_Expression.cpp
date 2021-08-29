#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> a;
        int n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if ('0' <= s[i] && s[i] <= '9')
                a.push(s[i] - '0');
            else {
                int x = a.top();
                a.pop();
                int y = a.top();
                a.pop();
                // cout << x << " " << y << "\n";
                if (s[i] == '+') {
                    a.push(x + y);
                } else if (s[i] == '-') {
                    a.push(x - y);
                } else if (s[i] == '*') {
                    a.push(x * y);
                } else if (s[i] == '/') {
                    a.push(x / y);
                }
            }
        }
        cout << a.top() << "\n";
    }
    return 0;
}