/*
 * Số Ugly là các số chỉ có ước số là 2, 3, 5.
 * Theo qui ước số 1 cũng là 1 số Ugly.
 * Dưới đây là 11 số Ugly đầu tiên: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15.
 * Cho số tự nhiên N, nhiệm vụ của bạn là tìm số Ugly thứ N.
 */

#include <bits/stdc++.h>
using namespace std;
#define max 10010

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < c) return b;
    return c;
}

vector<int> u(max);

void preCalc() {
    int p2 = 0, p3 = 0, p5 = 0;
    u[0] = 1;
    for (int i = 1; i < max; ++i) {
        u[i] = min(u[p2] * 2, u[p3] * 3, u[p5] * 5);
        if (u[i] == u[p2] * 2) p2++;
        if (u[i] == u[p3] * 3) p3++;
        if (u[i] == u[p5] * 5) p5++;
    }
}

int main() {
    int t;
    cin >> t;
    preCalc();
    // for (int i = 0; i < 10; ++i) {
    //     cout << u[i] << " ";
    // }
    // cout << "\n";
    while (t--) {
        int n;
        cin >> n;
        cout<<u[n-1]<<"\n";
    }
    return 0;
}