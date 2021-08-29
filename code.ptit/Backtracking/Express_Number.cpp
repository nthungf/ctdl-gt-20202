/*
Cho số nguyên dương N.
Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích
số tự nhiên N thành tổng các số tự nhiên nhỏ hơn hoặc bằng N.
Phép hoán vị của một cách được xem là giống nhau.
Ví dụ với N = 5 ta có kết quả là:
(5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> res;
vector<vector<int> > ress;
int vs[12];
int n, sum, dem;

void output() {
    for (int i = 0; i < ress.size(); i++) {
        cout << "(";
        for (int j = 0; j < ress[i].size() - 1; j++) {
            cout << ress[i][j] << " ";
        }
        cout << ress[i][ress[i].size() - 1] << ") ";
    }
    cout << "\n";
}

void Try(int i) {
    for (int j = n; j >= 1; j--) {
        if (sum + j <= n) {
            if (res.empty() || j <= res.back()) {
                sum += j;
                // cout << sum << '\n';
                res.push_back(j);
                if (sum == n) {
                    // output();
                    ress.push_back(res);
                    ++dem;
                } else
                    Try(i - j);
                sum -= j;
                res.pop_back();
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        dem = 0;
        memset(vs, 0, sizeof(vs));
        res.clear();
        ress.clear();
        cin >> n;
        Try(n);
        // cout << dem << "\n";
        output();
    }
    return 0;
}