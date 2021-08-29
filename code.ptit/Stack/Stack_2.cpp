/*
 * Yêu cầu bạn xây dựng một stack với các truy vấn sau đây:
“PUSH x”: Thêm phần tử x vào stack (0 ≤ x ≤ 1000).
“PRINT”: In ra phần tử đầu tiên của stack. Nếu stack rỗng, in ra “NONE”.
“POP”: Xóa phần tử đầu tiên của stack. Nếu stack rỗng, không làm gì cả.
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    cin.ignore();
    stack<int> a;
    string s;
    while (q--) {
        cin >> s;
        if (s == "PUSH") {
            int n;
            cin >> n;
            a.push(n);
        } else if (s == "POP" && !a.empty()) {
            a.pop();
        } else if (s == "PRINT") {
            if (a.empty())
                cout << "NONE\n";
            else
                cout << a.top() << "\n";
        }
    }
    return 0;
}