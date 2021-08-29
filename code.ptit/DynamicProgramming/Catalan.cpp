/*
C_n = 1 neu n=0
C_n = \Sigma_{i=0}^{n-1} C_i C_{n-i-1}  neu n > 0
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll Cat[101];

void preCalc() {
    Cat[0] = 1;
    Cat[1] = 1;
    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < i; j++) {
            Cat[i] += Cat[j] * Cat[i - j - 1];
        }
    }
    // for (int i = 0; i < 20; i++) {
    //     cout << Cat[i] << " ";
    // }
    // cout << "\n";
}

int main() {
    int t;
    cin >> t;
    preCalc();
    while (t--) {
        int n;
        cin >> n;
        cout << Cat[n] << "\n";
    }
    return 0;
}