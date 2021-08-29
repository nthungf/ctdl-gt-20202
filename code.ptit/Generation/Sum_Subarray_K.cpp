/*
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K.
Hãy viết chương trình liệt kê tất cả các dãy con của
dãy số A[] sao cho tổng các phần tử trong dãy con đó
đúng bằng K.
Dữ liệu vào trên bàn phím (n=5, K=50),
5 số dòng thứ 2 là các phần tử dãy A:

5 50
5 10 15 20 25
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a, b, res;
int n, k, ok = 1, dem = 0;

int Cal() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}

void Result() {
    for (int i = 0; i < n; i++) {
        if (b[i])
            res.push_back(a[i]);
    }
    sort(res.begin(), res.end());
    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
}

void Gen() {
    int i = n - 1;
    while (b[i] == 1) {
        b[i] = 0;
        i--;
    }
    if (i >= 0) {
        b[i] = 1;
    } else
        ok = 0;
}

int main() {
    cin >> n >> k;
    a.clear();
    b.clear();
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (ok) {
        res.clear();
        if (Cal() == k) {
            Result();
            ++dem;
        }
        Gen();
    }
    cout << dem << "\n";

    return 0;
}