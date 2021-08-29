/*
Cho dãy số A gồm N phần tử là các số nguyên.
Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> b(4);
    if (a[0] < 0 && a[1] < 0) b[0] = a[0] * a[1];
    b[1] = b[0] * a[n - 1];
    b[2] = a[n - 1] * a[n - 2];
    b[3] = b[2] * a[n - 3];
    ll max = LONG_MIN;
    for (int i = 0; i < 4; i++) {
        if (b[i] > max) max = b[i];
    }
    cout << max << "\n";
    return 0;
}