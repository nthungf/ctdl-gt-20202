/*
Cho ma trận vuông Ci,j cấp N (1<= i, j , N <= 10)
gồm N^2 số tự nhiên và số tự nhiên K
(các số trong ma trận không nhất thiết phải
khác nhau và đều không quá 100, K không quá 10^4).
Hãy viết chương trình lấy mỗi hàng, mỗi cột
duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.
*/

#include <bits/stdc++.h>
using namespace std;

int n, k, c[20][20], cot[20], a[20][20], sum = 0, dem = 0;
vector<int> res;
vector<vector<int> > resss;

void Output() {
    for (int i = 0; i < resss.size(); i++) {
        for (int j = 0; j < resss[i].size(); j++) {
            cout << resss[i][j] << " ";
        }
        cout << "\n";
    }
}

// hang i, cot j
void Try(int i) {
    for (int j = 1; j <= n; j++) {
        if (!cot[j]) {
            sum += c[i][j];
            cot[j] = 1;
            res.push_back(j);
            if (i == n && sum == k) {
                resss.push_back(res);
                ++dem;
            } else if (sum < k) {
                Try(i + 1);
            }
            sum -= c[i][j];
            cot[j] = 0;
            res.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cot[i] = 0;
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    Try(1);
    cout << dem << "\n";
    Output();
    return 0;
}