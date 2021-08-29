/*
Cho một xâu s.
Xâu F(s) được xác định bằng cách ghép xâu xâu s ban đầu
với xâu s sau khi đã được quay vòng sang bên phải 1 kí tự
(kí tự cuối cùng của s được chuyển lên đầu).
Thực hiện liên tiếp các bước cộng xâu như trên
với xâu mới thu được, ta có được xâu X.
Nhiệm vụ của bạn là hãy xác định kí tự thứ N trong xâu X là kí tự nào?
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll n;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            string tmp = s;
            char x = tmp.back();
            tmp.pop_back();
            tmp.insert(0, 1, x);
            s += tmp;
        }
        // cout << s << "\n";
        cout << s[n - 1] << "\n";
    }
    return 0;
}