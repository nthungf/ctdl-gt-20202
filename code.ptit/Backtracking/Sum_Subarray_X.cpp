/*
Cho mảng A[] gồm N số nguyên dương phân biệt và số X.
Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X.
Các số trong mảng A[] có thể được sử dụng nhiều lần.
Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số.
Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:
{2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.
*/

#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> a, res;
vector<vector<int> > ress;
int sum, dem;

void output() {
    for (int i = 0; i < ress.size(); i++) {
        cout << "{";
        for (int j = 0; j < ress[i].size() - 1; j++) {
            cout << ress[i][j] << " ";
        }
        cout << ress[i][ress[i].size() - 1] << "} ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = 0; j < a.size(); j++) {
        if (sum + a[j] <= x) {
            if (res.empty() || a[j] >= res[res.size() - 1]) {
                sum += a[j];
                // cout << "+" << a[j] << " = " << sum << "\n";
                res.push_back(a[j]);
                if (sum == x) {
                    ress.push_back(res);
                    ++dem;
                } else
                    Try(x - a[j]);
                sum -= a[j];
                // cout << "-" << a[j] << " = " << sum << "\n";
                res.pop_back();
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        a.clear();
        a.resize(n);
        res.clear();
        ress.clear();
        sum = 0;
        dem = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        Try(x);
        if (dem > 0) cout << dem << " ";
        else
            cout << "-1";
        output();
    }
    return 0;
}