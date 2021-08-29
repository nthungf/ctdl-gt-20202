/*
Cho xâu nhị phân X[], nhiệm vụ của bạn là hãy đưa ra
xâu nhị phân trước của X[].
Ví dụ X[] =”111111” thì xâu nhị phân trước của X[] là “111110”.
Với xâu X[] =“000001” thì xâu nhị trước của X[] là “000000”.
Chú ý: nếu xâu dữ liệu trong input là xâu đầu tiên thì trước nó
sẽ là xâu cuối cùng.
*/

#include <bits/stdc++.h>
using namespace std;

void gen(string &s) {
    int i = s.size() - 1;
    while (s[i] == '0') {
        s[i] = '1';
        i--;
    }
    if (i >= 0) {
        s[i] = '0';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        gen(s);
        cout << s << "\n";
    }
    return 0;
}