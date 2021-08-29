/*
Cho 5 số nguyên dương A, B, C, D, E.
Bạn có thể hoán vị các phần tử cho nhau,
hãy đặt các dấu biểu thức +, -, * sao cho
biểu thức sau đúng:
[[[A o(1) B] o(2) C] o(3) D] o(4) E = 23
*/

#include <bits/stdc++.h>
using namespace std;

int a[10], b[10], used[10];
int res, check;

void Result() {
    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}

void TryOp(int i) {
    // Add
    res += b[i + 1];
    if (i == 3) {
        if (res == 23)
            check = 1;
    } else
        TryOp(i + 1);
    res -= b[i + 1];
    // Subtract
    res -= b[i + 1];
    if (i == 3) {
        if (res == 23)
            check = 1;
    } else
        TryOp(i + 1);
    res += b[i + 1];
    // Multiply
    res *= b[i + 1];
    if (i == 3) {
        if (res == 23)
            check = 1;
    } else
        TryOp(i + 1);
    res /= b[i + 1];
}

void TryPm(int i) {
    for (int j = 0; j < 5; j++) {
        if (!used[j]) {
            b[i] = a[j];
            used[j] = 1;
            if (i == 4) {
                // Result();
                res = b[0];
                TryOp(0);
            } else
                TryPm(i + 1);
            used[j] = 0;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        fill(used, used + 10, 0);
        for (int i = 0; i < 5; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        check = 0;
        TryPm(0);
        if (check) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}