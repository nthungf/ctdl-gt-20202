/*
Trong quá trình gõ một dòng văn bản, chúng ta thường
sử dụng phím sang trái, sang phải hoặc xóa lùi (backspace).
Cho một dãy ký tự mô tả các thao tác gõ phím, trong đó:

Ký tự ‘-’ mô tả phím backspace (xóa lùi).
Ký tự ở phía trước con trỏ (nếu có) sẽ bị xóa.

Ký tự ‘<’ mô tả phím di chuyển sang trái.
Con trỏ sẽ sang trái 1 ký tự nếu có thể.

Ký tự ‘>’ mô tả phím di chuyển sang phải.
Con trỏ sẽ sang phải 1 ký tự nếu có thể.

Các ký tự khác là các chữ cái Tiếng Anh
(in hoa hoặc in thường). Bàn phím để ở chế độ Insert.
Tức là nếu con trỏ không ở cuối dòng thì khi chèn
các ký tự sẽ đẩy các ký tự khác sang phải một vị trí.

Hãy thử tính toán và viết ra kết quả tương ứng.
*/
// co n ki tu(0,...,n-1) va n+1 vi tri(0,...,n);
// vi tri i nam truoc ki tu thu i

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    s.clear();
    getline(cin, s);
    string res;
    res.clear();
    stack<char> before, after;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            if (!before.empty()) {
                // cout << "del " << before.top() << "\n";
                before.pop();
            }
        } else if (s[i] == '>') {
            if (!after.empty()) {
                // cout << ">\n";
                before.push(after.top());
                after.pop();
            }
        } else if (s[i] == '<') {
            if (!before.empty()) {
                // cout << "<\n";
                after.push(before.top());
                before.pop();
            }
        } else {
            // cout << "insert " << s[i] << "\n";
            before.push(s[i]);
        }
    }
    string b, a;
    while (!before.empty()) {
        b += before.top();
        before.pop();
    }
    while (!after.empty()) {
        a += after.top();
        after.pop();
    }
    reverse(b.begin(), b.end());
    cout << b + a << "\n";
    return 0;
}