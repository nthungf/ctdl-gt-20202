/*
Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN }
và số tự nhiên K (K<=N<=100).
Ta gọi một dãy con tăng dần bậc K của dãy số AN
là một dãy các số gồm K phần tử trong dãy đó thỏa mãn
tính chất tăng dần.
Bài toán được đặt ra là in ra màn hình
số các dãy con tăng dần bậc K của dãy số AN
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, a[105], b[105], ok = 1;

void output() {
    for (int i = 1; i <= k; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int check() {
    for (int i = 1; i < k; ++i) {
        if (b[a[i]] > b[a[i + 1]]) return 0;
    }
    return 1;
}

void gen() {
    int i = k;
    while (a[i] == n - k + i) {
        i--;
    }
    if (i > 0) {
        a[i]++;
        for (int j = i + 1; j <= n; ++j) {
            a[j] = a[i] + j - i;
        }
    } else {
        ok = 0;
    }
}

int main() {
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
        a[i] = i;
        cin >> b[i];
    }
    int dem = 0;
    while (ok) {
        if (check()) {
            // cout << "--";
            ++dem;
        }
        // output();
        gen();
    }
    cout << dem << "\n";
    return 0;
}
