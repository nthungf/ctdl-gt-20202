/*
Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa.
Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái
(không trùng nhau) và sắp xếp lại theo thứ tự từ điển.

Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT
*/

#include <bits/stdc++.h>
using namespace std;
int n, k, ok;

void output() {}

void gen(string &s) {
    int i = k - 1;
    while (s[i] - 'A' == n - k + i) {
        i--;
    }
    if (i >= 0) {
        s[i]++;
        for (int j = i + 1; j < k; j++) {
            s[j] = s[i] + j - i;
        }
    } else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ok = 1;
        cin >> n >> k;
        string s;
        for (int i = 0; i < k; i++) {
            s.push_back('A' + i);
        }

        while (ok) {
            // output();
            cout << s << "\n";
            gen(s);
        }
    }
    return 0;
}