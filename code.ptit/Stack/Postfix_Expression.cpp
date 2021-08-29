#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<int> a;
        for (int i = 0; i < s.size(); ++i) {
            if ('0' <= s[i] && s[i] <= '9') a.push(s[i] - '0');
            else {
                int x = a.top();
                a.pop();
                int y = a.top();
                a.pop();
                if (s[i] == '+') a.push(x + y);
                else if (s[i] == '-')
                    a.push(y - x);
                else if (s[i] == '*')
                    a.push(x * y);
                else if (s[i] == '/')
                    a.push(y / x);
            }
        }
        cout << a.top() << "\n";
    }
    return 0;
}
