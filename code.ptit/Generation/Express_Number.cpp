/*
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê
tất cả các cách phân tích số tự nhiên N thành tổng các số
tự nhiên nhỏ hơn hoặc bằng N.
Phép hoán vị vủa một cách được xem là giống nhau.
Ví dụ với N = 5 ta có kết quả là:
(5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1),
(2, 1, 1, 1), (1, 1, 1, 1, 1) .
*/

#include <bits/stdc++.h>
using namespace std;

int X[12], ok = 1, n, k;

void Output() {
    cout << "(";
    int i = 1;
    while (X[i + 1] != 0) {
        cout << X[i] << " ";
        i++;
    }
    cout << X[i] << ") ";
}

void nextDivisor() {

    int R, S, D, i = k;
    while (i > 0 && X[i] == 1) {
        i--;
    }
    if (i > 0) {
        X[i]--;
        D = k - i + 1;
        R = D / X[i];
        S = D % X[i];
        k = i;
        if (R > 0) {
            for (int j = i + 1; j <= i + R; j++) {
                X[j] = X[i];
            }
            k += R;
        }
        if (S > 0) {
            k++;
            X[k] = S;
        }
    } else
        ok = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(X, 0, sizeof(X));
        cin >> n;
        k = 1;
        X[k] = n;
        ok = 1;
        while (ok) {
            Output();
            nextDivisor();
        }
        cout << "\n";
    }
    return 0;
}