/*
Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:
X[1] = “0”
X[2] = “1”
X[n] = X[n-2] + X[n-1] với n>2
Với phép cộng (+) là phép nối hai xâu với nhau.
Cho hai số tự nhiên N và K
(1<N<93; K đảm bảo trong phạm vi của xâu X[N]).
Hãy xác định ký tự thứ K trong xâu X[N]
là ký tự ‘0’ hay ký tự ‘1’.
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
        ll n, k;
        cin >> n >> k;
        while (n > 2) {
            if (k > fib[n - 2]) {
                k -= fib[n - 2];
                n--;
            } else
                n -= 2;
            if (n <= 2)
                break;
        }
        if (n == 2)
            cout << '1';
        else
            cout << '0';
        cout << '\n';
    }
    return 0;
}