/*
Cho số nguyên dương N.
Nhiệm vụ của bạn là hãy liệt kê tất cả
các cách phân tích số tự nhiên N thành tổng
các số tự nhiên nhỏ hơn hoặc bằng N.
Phép hoán vị vủa một cách được xem là giống nhau.
Ví dụ với N = 5 ta có kết quả là:
(5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1),
(2, 1, 1, 1), (1, 1, 1, 1, 1) .
*/

#include <bits/stdc++.h>
using namespace std;

void output(vector<int> a) {
    cout << '(';
    for (int i = 0; a[i] > 0; i++) {
        cout << a[i] << ' ';
    }
    cout << ') ';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int ok = 1;
        cin >> n;
        vector<int> a(n);
        a[0] = n;
        while (ok) {
            int i = n - 1;
            while (i > 0 && a[i] <= 1)
                i--;
            a[i]--;
        }
    }
    return 0;
}