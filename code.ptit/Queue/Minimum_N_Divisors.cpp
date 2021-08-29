/*
Cho số nguyên dương N. Nhiệm vụ của bạn là tìm số K nhỏ nhất,
sao cho K có đúng N ước. Input đảm bảo rằng đáp án không vượt quá 10^18.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll x = 1;
        int dem = 0;
        while (1) {
            dem = 0;
            for (int i = 1; i * i <= x; ++i) {
                if (x % i == 0) {
                    if (i == x / i) dem++;
                    else
                        dem += 2;
                }
            }
            if (dem >= n) break;
            ++x;
        }
        if (dem == n) {
            cout << x << "\n";
        }
    }
    return 0;
}
