/*
Problem
*/

#include <bits/stdc++.h>
using namespace std;

int N, W, ok = 1, fopt;
vector<int> a, c, X, res;

void output() {
    for (int i = 1; i <= N; ++i) {
        cout << X[i] << " ";
    }
    cout << "\n";
}

void update() {
    int val = 0, wei = 0;
    for (int i = 1; i <= N; ++i) {
        val += (c[i] * X[i]);
        wei += (a[i] * X[i]);
    }
    if (val > fopt && wei <= W) {
        fopt = val;
        res = X;
    }
}

void gen() {
    int i = N;
    while (X[i] == 1) {
        X[i] = 0;
        i--;
    }
    if (i > 0) {
        X[i] = 1;
    } else
        ok = 0;
}

int main() {
    cin >> N >> W;
    a.resize(N + 5);
    c.resize(N + 5);
    X.resize(N + 5);
    res.resize(N + 5);
    for (int i = 1; i <= N; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    fopt = INT_MIN;
    while (ok) {
        // cout << val << " " << wei << "\n";
        update();
        gen();
    }
    cout << fopt << "\n";
    for (int i = 1; i <= N; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}
