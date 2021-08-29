/*
Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’.
Biểu thức P có thể viết đúng hoặc không đúng.
Nhiệm vụ của bạn là tìm độ dài lớn nhất viết đúng của P.
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
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                a.push('(');
            } else if (s[i] == ')') {
                if (a.empty() || a.top() == ')') a.push(')');
                else
                    a.pop();
            }
        }
        cout << s.size() - a.size() << "\n";
    }
    return 0;
}