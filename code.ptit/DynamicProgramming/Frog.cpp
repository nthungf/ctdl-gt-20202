/*
Một con ếch có thể nhảy 1, 2, 3 bước để có thể
lên đến một đỉnh cần đến. Hãy đếm số các cách
con ếch có thể nhảy đến đỉnh.
*/

// f[i] = f[i-1] + f[i-2] + f[i-3];

#include <bits/stdc++.h>
using namespace std;

long long f[60];

void preCalc() {
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4; i <= 50; i++) {
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}