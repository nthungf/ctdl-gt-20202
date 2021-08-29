/*
Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B
được gọi là dãy xâu Fibonacci nếu thỏa mãn tính chất:
G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1).
Với phép cộng (+) là phép nối hai xâu với nhau.
Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1)
của xâu Fibonacci thứ n.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll fib[100];
void preCalc() {
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < 100; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        ll n, i;
        cin >> n >> i;
        // char res = ' ';
        // cout << size << '\n';
        while (n > 2) {
            // cout << i << " " << fib[n - 2] << " " << fib[n] << "\n";
            // tim vi tri cua i trong xau G(n-1)
            if (i > fib[n - 2]) {
                i -= fib[n - 2];
                // cout << i << " ";
                n--;
            } else
                n -= 2;
            if (n <= 2) break;
        }
        // cout << n << " " << i << "\n";
        if (n == 2) {
            cout << 'B';
        } else {
            cout << 'A';
        }
        cout << "\n";
        // cout << n - 2 << " " << i << "\n";
    }
    return 0;
}